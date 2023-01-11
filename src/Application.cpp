#include "Application.h"
#include "entities/account/Admin.h"
#include "utils/io/DatabaseFile.h"
#include <iomanip>
#include <iostream>
#include <sys/stat.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__CYGWIN__)
#define PLATFORM_DETECTED 1
#elif defined(__APPLE__) || defined(linux)
#define PLATFORM_DETECTED 1
#include <sys/ioctl.h>
#endif
#ifndef PLATFORM_DETECTED
#error Could not detect operating system platform
#endif

bool Application::detected_database() {
    struct stat sb {};
    if (stat(this->database_path.c_str(), &sb) == 0) {
        return true;
    }
    return false;
}

void Application::init_database() {
    int status = -1;

#if defined(__APPLE__) || defined(linux)
    status = mkdir(this->database_path.c_str(), 0777);
#endif
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__CYGWIN__)
    status = mkdir(this->database_path.c_str());
#endif

    if (status != 0) {
        throw std::runtime_error("Unable to create database directory.\n");
    }

    this->save_database();
}

void Application::load_database() {
    // admin database file
    utils::io::DatabaseFile admin_dtb(this->database_path + "admin.dat");
    admin_dtb.read();
    this->admin.from_map(admin_dtb[0]);
    //member database file
    std::vector<std::map<std::string, std::string>> data_member;
    data_member.clear();

    utils::io::DatabaseFile members_dtb(this->database_path + "members.dat");
    members_dtb.read();
    members_dtb >> data_member;
    for (auto &record : data_member) {
        this->members.emplace_back();
        this->members.back().from_map(record);
    }
    //houses database file
    std::vector<std::map<std::string, std::string>> data_houses;
    data_houses.clear();

    utils::io::DatabaseFile houses_dtb(this->database_path + "houses.dat");
    houses_dtb.read();
    houses_dtb >> data_houses;
    for (auto &record : data_houses) {
        this->houses.emplace_back();
        this->houses.back().from_map(record);
    }
    //house reviews database
    std::vector<std::map<std::string, std::string>> data_house_reviews;
    data_house_reviews.clear();

    utils::io::DatabaseFile house_reviews_dtb(this->database_path + "house_reviews.dat");
    house_reviews_dtb.read();
    house_reviews_dtb >> data_house_reviews;
    for (auto &record : data_house_reviews) {
        this->house_reviews.emplace_back();
//        this->house_reviews.back().from_map(record);
    }
    //occupant reviews database
    std::vector<std::map<std::string, std::string>> data_occupant_reviews;
    data_occupant_reviews.clear();

    utils::io::DatabaseFile occupant_reviews_dtb(this->database_path + "occupant_reviews.dat");
    occupant_reviews_dtb.read();
    occupant_reviews_dtb >> data_occupant_reviews;
    for (auto &record : data_occupant_reviews) {
        this->occupant_reviews.emplace_back();
//        this->occupant_reviews.back().from_map(record);
    }
    //requests database
    std::vector<std::map<std::string, std::string>> data_requests;
    data_requests.clear();

    utils::io::DatabaseFile requests_dtb(this->database_path + "requests.dat");
    requests_dtb.read();
    requests_dtb >> data_requests;
    for (auto &record : data_requests) {
        this->requests.emplace_back();
        this->requests.back().from_map(record);
    }
    //
    //    file.read(this->database_path + "cities.dat");
    //    file >> data;
}

void Application::save_database() {
    utils::io::DatabaseFile admin_dtb(this->database_path + "admin.dat");
    std::vector<std::map<std::string, std::string>> admins;
    std::map<std::string, std::string> admin;
    admin.emplace("username", "admin");
    admin.emplace("password", "admin");
    admins.push_back(admin);
    admin_dtb << admins;
    admin_dtb.write();

    utils::io::DatabaseFile members_dtb(this->database_path + "members.dat");
    std::vector<std::map<std::string, std::string>> members;
    for (auto member : this->members) members.push_back(member.to_map());
    members_dtb << members;
    members_dtb.write();

    utils::io::DatabaseFile houses_dtb(this->database_path + "houses.dat");
    std::vector<std::map<std::string, std::string>> houses;
    for (auto house : this->houses) houses.push_back(house.to_map());
    houses_dtb << houses;
    houses_dtb.write();

    utils::io::DatabaseFile requests_dtb(this->database_path + "requests.dat");
    std::vector<std::map<std::string, std::string>> requests;
    for (auto request : this->requests) requests.push_back(request.to_map());
    requests_dtb << requests;
    requests_dtb.write();

    utils::io::DatabaseFile house_reviews_dtb(this->database_path + "house_reviews.dat");
    house_reviews_dtb.write();

    utils::io::DatabaseFile occupant_reviews_dtb(this->database_path + "occupant_reviews.dat");
    occupant_reviews_dtb.write();

    std::vector<std::map<std::string, std::string>> cities;

    std::map<std::string, std::string> hanoi;
    hanoi.emplace("name", "Ha Noi");
    cities.push_back(hanoi);

    std::map<std::string, std::string> danang;
    danang.emplace("name", "Da Nang");
    cities.push_back(danang);

    std::map<std::string, std::string> saigon;
    saigon.emplace("name", "Sai Gon");
    cities.push_back(saigon);

    utils::io::DatabaseFile cities_dtb(this->database_path + "cities.dat");
    cities_dtb << cities;
    cities_dtb.write();
}

void Application::reset_database() {
    houses.clear();
    members.clear();
    //todo clear more db later
    cities.clear();
    house_reviews.clear();
    occupant_reviews.clear();
    requests.clear();

}

bool Application::login(const account::Account &account) {
    std::string buffer;

    std::cout << "Enter password for " << account.get_username() << ": ";
    std::getline(std::cin, buffer);

    if (account.authenticate(buffer)) return true;

    std::cout << "Wrong password entered!\n";
    return false;
}

void Application::guest_menu() {
    bool back = false;

    while (!back) {
        std::cout << "\nGuest menu:\n"
                     "==============================\n"
                     "0. Back.\n"
                     "1. View all house details.\n"
                     "2. Register as member account.\n";

        switch (Application::prompt_choice(1, 3)) {
            case 1:
                std::cout << "House details \n";
                this->guest_view_house();
                break;
            case 2:
                std::cout << "Registered...\n";
                this->register_member();
                break;
            case 0:
                back = true;
                break;
        }
    }
}
void Application::house_details(std::string buffer, std::string id) {
    std::string city;
    int credit_score, minimum_rating_score;
    std::cout << "Please enter the new location of your house: \n";
    std::cout
        << "1. Ha Noi \n"
        << "2. Hue \n"
        << "3. Sai Gon \n";
    switch (Application::prompt_choice(1, 3)) {
        case 1:
            city = "Ha Noi";
            break;
        case 2:
            city = "Hue";
            break;
        case 3:
            city = "Sai Gon";
            break;
    }
    // todo add the conditions of setting credit and minimum_rating_score
    std::cout << "\nPlease enter the credit point for your house: ";
    std::cin >> credit_score;
    std::cout << "\nPlease enter the minimum score rating to occupy the house: ";
    std::cin >> minimum_rating_score;
    this->houses.emplace_back(city, buffer, id, credit_score, minimum_rating_score);
}
void Application::add_house(account::Member &current_member) {
    bool back = false;
    std::string buffer;
    buffer = current_member.get_username();
    std::string id = current_member.get_id();
    for (int i = 0; i < this->houses.size(); i++) {
        if (current_member.get_id() == this->houses[i].get_house_id()) {
            std::cout << "You can't add house anymore, do you want to remove your current house:\n"
                      << "1. Yes\n"
                      << "2. No\n";
            switch (Application::prompt_choice(1, 2)) {
                case 1:
                    this->houses.erase(this->houses.begin() + i);
                    std::cout << "You have successfully removed your current house !!! \n";
                    break;
                case 2:
                    back = true;
                    break;
            }
        }
    }
    if (!back) {
        std::cout
            << "Please enter the details of your house:\n"
            << "0. Back\n"
            << "1. Continue\n";
        switch (Application::prompt_choice(1, 2)) {
            case 0:
                back = true;
                break;
            case 1:
                this->house_details(buffer, id);
                break;
        }
    }
}

std::vector<house::House> Application::list_house_available(account::Member &current_member) {
    bool back = true;
    std::string buffer;
    std::vector<house::House> houses_in_city;
    std::cout << "Please select the city you want to search house for: \n"
              << "0. Back \n"
              << "1. Ha Noi \n"
              << "2. Hue \n"
              << "3. Sai Gon \n";
    switch (Application::prompt_choice(1, 3)) {
        case 1:
            buffer = "Ha Noi";
            back = false;
            break;
        case 2:
            buffer = "Hue";
            back = false;
            break;
        case 3:
            buffer = "Sai Gon";
            back = false;
            break;
    }
    if (!back) {
        for (int i = 0; i < this->houses.size(); i++) {
            if (current_member.get_id() != this->houses[i].get_house_id()
                && current_member.get_credits() >= this->houses[i].get_credit()
                && current_member.get_rating() >= this->houses[i].get_minimum_review_score()
                && this->houses[i].getCity() == buffer) {
                std::cout << "House's ID: "
                          << this->houses[i].get_house_id()
                          << " | Owner: "
                          << this->houses[i].getHouseOwner()
                          << " | Credit per day: "
                          << this->houses[i].get_credit()
                          << "\n";
                houses_in_city.push_back(houses[i]);
            }
        }
    }
    if (houses_in_city.empty()) {
        std::cout << "\nThere are no available houses in this city!\n";
    }
    return houses_in_city;
}

bool Application::check_house_request(account::Member &current_member, std::vector<house::House> house_in_city) {
    bool back = false;
    house::HouseRequest requester;
    std::string house_ID;

    if (house_in_city.empty()) {
        return true;
    }
    std::map<std::string, std::string> house_map;
    while (!back) {
        std::cout << "\nPlease Enter a valid House ID that you want to request: \n";
        int houseID = prompt_choice(1, members.size());
        for (auto house : house_in_city) {
            house_map = house.to_map();
            for (auto it = house_map.cbegin(); it != house_map.cend(); ++it) {
                if (it->first == "houseID" && std::stoi(it->second) == houseID) {
                    std::cout << "\n You have requested House ID: " << it->second << std::endl;
                    requester.setHouseRequested(&house);
                    house_ID = requester.getHouseRequested()->get_house_id();
                    back = true;
                }
            }
        }
    }
    requester.setRequester(&current_member);
    std::string requester_ID = current_member.get_id();
    requester.setRequesterId(requester_ID);
    requester.setHouseRequestedId(house_ID);
    requests.emplace_back(requester_ID, house_ID);
    return true;
}

void Application::member_menu() {
    bool back = true;
    std::string buffer;
    account::Member *current_member;
    std::vector<house::House> temp_vector;

    std::cout << "Enter your username: ";
    std::getline(std::cin, buffer);
    for (auto &member : this->members) {
        if (member.get_username() == buffer) {
            back = !this->login(member);
            current_member = &member;
            break;
        }
    }
    if (back) std::cout << "No user with user name '" << buffer << "' found!\n";

    while (!back) {
        std::cout << "\nMember menu:\n"
                     "===============================================\n"
                     "0. Back. \n"
                     "1. View information.\n"
                     "2. Add house to my renting list.\n"
                     "3. List all house are available to be occupied.\n"
                     "4. Request house to occupy. \n"
                     "5. Accept/Decline incoming requests. \n"
                     "6. Rate occupied house. \n"
                     "7. Rate occupiers who had used my house. \n";

        switch (Application::prompt_choice(1, 7)) {
            case 1:
                std::cout << "\nUsername: " << current_member->get_username() << "\n"
                                                                                 "First name: "
                          << current_member->get_first_name() << "\n"
                          << "Last name: " << current_member->get_last_name() << "\n"
                          << "Phone number: " << current_member->get_phone_number() << "\n"
                          << "Credits: " << current_member->get_credits() << "\n"
                          << "Rating: " << std::fixed << std::setprecision(1) << current_member->get_rating() << "\n\n";
                break;
            case 2:
                Application::add_house(*current_member);
                break;
            case 3:
                Application::list_house_available(*current_member);
                break;
            case 4:
                temp_vector = Application::list_house_available(*current_member);
                if (Application::check_house_request(*current_member, temp_vector)) break;
            case 5:
                // todo Accept/Decline incoming requests
                break;
            case 6:
                // todo Rate occupied house
                break;
            case 7:
                // todo Rate occupiers who had used my house
                break;
            case 0:
                back = true;
                break;
        }
    }
}

void Application::guest_view_house() {
    // todo add conditions so that the guest cannot view all house info
    std::cout << "\nhouseLocation |\thouseID | houseOwner |\n";
    for (auto house : this->houses) {
        std::map<std::string, std::string> house_map;
        house_map = house.to_map();
        std::cout << std::endl;
        for (auto it = house_map.cbegin(); it != house_map.cend(); ++it) {
            std::cout << it->second + "\t|\t";
        }
    }
    std::cout << std::endl;
}

void Application::admin_menu() {
    if (this->login(this->admin)) {
        bool back = false;

        while (!back) {
            std::cout << "\nAdmin menu:\n"
                         "=============================================\n"
                         "0. Back.\n"
                         "1. View all house details and member details.\n";

            switch (Application::prompt_choice(1, 2)) {
                case 1:
                    // View all house details and member details
                    for (auto member : this->members) {
                        std::map<std::string, std::string> member_map;
                        member_map = member.to_map();
                        std::cout << "======================================\n"
                                  << member.get_username() + "'s DETAILED INFO:\n"
                                  << "======================================\n";
                        for (auto it = member_map.cbegin(); it != member_map.cend(); ++it) {
                            std::cout << it->first << " " << it->second << "\n";
                            if (it->first == "username") {
                                for (auto house : this->houses) {
                                    if (house.getHouseOwner() == it->second) {
                                        std::cout << "house's location: " << house.getCity() << "\n";
                                        // todo implement more house info later
                                    }
                                }
                            }
                        }
                        std::cout << std::endl;
                    };
                case 0:
                    back = true;
                    break;
            }
        }
    }
}

bool Application::register_member() {
    std::string username, password, first_name, last_name, phone_number, memberID;

    std::cout << "Enter your new username: ";
    std::getline(std::cin, username);
    std::cout << "Enter your new password: ";
    std::getline(std::cin, password);

    for (const auto &member : this->members) {
        if (member.get_username() == username) {
            std::cout << "Error: Username '" << username << "' already exists.\n";
            return false;
        }
    }

    if (password.empty()) {
        std::cout << "Error: Your password cannot be empty.\n";
        return false;
    }

    for (auto c : password) {
        if (c == ' ') {
            std::cout << "Error: Your password cannot contain space character.\n";
            return false;
        }
    }

    std::cout << "Enter your first name: ";
    std::getline(std::cin, first_name);

    std::cout << "Enter your last name: ";
    std::getline(std::cin, last_name);

    std::cout << "Enter your phone number: ";
    std::getline(std::cin, phone_number);

    memberID = std::to_string(this->members.size() + 1);

    this->members.emplace_back(memberID, username, password, first_name, last_name, phone_number);
    return true;
}

int Application::prompt_choice(unsigned min, unsigned max) {
    int choice = -1;
    std::string buffer;

    std::cout << "Enter your choice: ";
    std::getline(std::cin, buffer);
    try {
        choice = std::stoi(buffer);
    } catch (std::invalid_argument &e) {
        choice = -1;
    } catch (std::out_of_range &e) {
        choice = -1;
    }

    while (choice == -1) {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, buffer);

        if (choice < min || max < choice) choice = -1;
        try {
            choice = std::stoi(buffer);
        } catch (std::invalid_argument &e) {
            choice = -1;
        } catch (std::out_of_range &e) {
            choice = -1;
        }
    }

    return choice;
}

Application::Application() {
    this->quit = false;
    this->login_type = NONE;
    this->database_path = "./data/";
}

void Application::main_loop() {
    std::cout << "======================================\n"
              << "EEET2482/COSC2082 ASSIGNMENT\n"
              << "VACATION HOUSE EXCHANGE APPLICATION\n"
              << "\n"
              << "Instructors: Mr. Linh Tran & Phong Ngo\n"
              << "Group: Group 9\n"
              << "s3963207, Do Le long An\n"
              << "s3817747, Hoang Ngoc Duan\n"
              << "s3941773, Nguyen Phuong Nam\n"
              << "s3877562, Vo Tuong Minh"
              << "\n======================================\n\n";

    if (!this->detected_database()) {
        this->init_database();
    }
    this->load_database();

    // Main application loop
    while (!this->quit) {
        std::cout << "\nMAIN MENU\n"
                  << "=========================\n"
                  << "--> 0. Exit\n"
                  << "--> 1. Login as Guest\n"
                  << "--> 2. Login as existing Member\n"
                  << "--> 3. Register as new Member\n"
                  << "--> 4. Login as Admin\n"
                  << "--> 5. Reset application\n";

        switch (Application::prompt_choice(1, 5)) {
            case 1:
                this->guest_menu();
                break;
            case 2:
                this->member_menu();
                break;
            case 3:
                if (!this->register_member()) std::cout << "Could not create your Member account.\n";
                break;
            case 4:
                this->admin_menu();
                break;
            case 5:
                this->reset_database();
                break;
            case 0:
                this->quit = true;
            default: break;
        }
    }

    this->save_database();
}
