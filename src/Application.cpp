#include "Application.h"
#include "entities/account/Admin.h"
#include "utils/io/DatabaseFile.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
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
        this->house_reviews.back().from_map(record);
    }
    //occupant reviews database
    std::vector<std::map<std::string, std::string>> data_occupant_reviews;
    data_occupant_reviews.clear();

    utils::io::DatabaseFile occupant_reviews_dtb(this->database_path + "occupant_reviews.dat");
    occupant_reviews_dtb.read();
    occupant_reviews_dtb >> data_occupant_reviews;
    for (auto &record : data_occupant_reviews) {
        this->occupant_reviews.emplace_back();
        this->occupant_reviews.back().from_map(record);
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
    std::vector<std::map<std::string, std::string>> house_reviews;
    for (auto house_review : this->house_reviews) house_reviews.push_back(house_review.to_map());
    house_reviews_dtb << house_reviews;
    house_reviews_dtb.write();

    utils::io::DatabaseFile occupant_reviews_dtb(this->database_path + "occupant_reviews.dat");
    std::vector<std::map<std::string, std::string>> occupant_reviews;
    for (auto occupant_review : this->occupant_reviews) occupant_reviews.push_back(occupant_review.to_map());
    occupant_reviews_dtb << occupant_reviews;
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
    double rating_score;
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
    this->houses.emplace_back(city, buffer, id, credit_score, minimum_rating_score, rating_score);
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
                && current_member.getRatingScore() >= this->houses[i].get_minimum_review_score()
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

bool Application::request_house_to_occupy(account::Member &current_member, std::vector<house::House> house_in_city) {
    int choice;
    bool back = false;
    bool valid = false;
    std::map<std::string, std::string> house_map;
    house_map.clear();

    std::string house_request_ID, request_status, requester_ID, requester_username;
    if (house_in_city.empty()) {
        return true;
    }
    while (!back && !house_in_city.empty()) {
        while (!valid) {
            std::cout << "\nPlease Enter a valid House ID that you want to request \n";
            choice = prompt_choice(1, members.size());
            for (auto house : house_in_city) {
                house_map = house.to_map();
                if (house_map["houseID"] == std::to_string(choice)) {
                    house_map.clear();
                    valid = true;
                }
            }
        }
        for (auto request : this->requests) {
            if (request.getHouseRequestedId() == std::to_string(choice) && request.getRequesterUsername() == current_member.get_username()) {
                std::cout << "You have already requested for this house!\n";
                return true;
            }
        }
        std::cout << "\nYou have requested House ID: " << std::to_string(choice) << "\n";
        house_request_ID = std::to_string(choice);
        requester_ID = current_member.get_id();
        requester_username = current_member.get_username();
        request_status = "pending";
        back = true;
    }
    this->requests.emplace_back(requester_ID, house_request_ID, requester_username, request_status);
    return true;
}

void Application::check_house_request_list(account::Member &current_member) {
    house::HouseRequest request_el;
    std::string accepted = "Accepted";
    std::string rejected = "Rejected";
    std::string house_request_ID, request_status, requester_ID, requester_username, house_requestedID;
    std::vector<house::HouseRequest> request_list;
    std::map<std::string, std::string> temp_map;
    bool valid = false;
    bool back = false;

    std::cout << "\tHere's the incoming request to your house: \n";
    for (auto request : this->requests) {
        if (current_member.get_id() == request.getHouseRequestedId()) {
            std::cout << "--> Requester username: " << request.getRequesterUsername()
                      << " | Requester ID: " << request.getRequesterId()
                      << " | Request Status: " << request.getRequestStatus()
                      << " <--\n";
            request_list.emplace_back(request);
        }
    }
    if (request_list.empty()) {
        std::cout << "\tYou don't have any requests!\n";
        back = true;
    }
    if (!back) {
        std::cout << "\nDo you want to want to accept/reject these request: \n"
                  << "1. Yes\n"
                  << "2. No\n"
                  << "\n";
        switch (Application::prompt_choice(1, 2)) {
            case 1:
                int choice;
                while (!valid) {
                    std::cout << "\nPlease Enter a valid Requester ID that you want to accept \n";
                    choice = prompt_choice(1, members.size());
                    for (auto request : request_list) {
                        temp_map = request.to_map();
                        if (temp_map["requester_ID"] == std::to_string(choice)) {
                            temp_map.clear();
                            valid = true;
                        }
                    }
                }
                for (int i = 0; i < this->requests.size(); i++) {
                    if (current_member.get_id() == this->requests[i].getHouseRequestedId()) {
                        if (this->requests[i].getRequesterId() == std::to_string(choice)) {
                            std::cout << "Please select your action on this request: \n"
                                      << "1. Accept\n"
                                      << "2. Reject\n";
                            switch (Application::prompt_choice(1, 2)) {
                                case 1:
                                    request_status = accepted;
                                    this->requests[i].setRequestStatus(request_status);
                                    std::cout << "You have accepted this request !!!\n";
                                    house_requestedID = current_member.get_id();
                                    Application::update_credit(std::to_string(choice), house_requestedID);
                                    Application::remove_request(request_list, house_requestedID, std::to_string(choice));
                                    break;
                                case 2:
                                    request_status = rejected;
                                    this->requests[i].setRequestStatus(request_status);
                                    std::cout << "You have rejected this request !!!\n";
                                    break;
                            }
                        }
                    }
                }
                break;
            case 2:
                back = true;
                break;
        }
    }
}
void Application::remove_request(std::vector<house::HouseRequest> request_list, std::string house_requestedID, std::string requester_ID) {
    for (int i=0; i < requests.size(); i++) {
        for (auto req : request_list) {
            if (requests[i].getRequesterUsername() == req.getRequesterUsername()
                && requests[i].getHouseRequestedId() == house_requestedID) {
                requests.erase(requests.begin() + i);
            }
        }
    }
    this->occupant_reviews.emplace_back(house_requestedID,"",0,requester_ID);
}
void Application::update_credit(std::string requester_ID, std::string house_requestedID) {
    for (int i = 0; i < members.size(); i++) {
        if (members[i].get_id() == requester_ID) {
            for (auto house : houses) {
                if (house.get_house_id() == house_requestedID) {
                    members[i].setCredits(members[i].get_credits()-house.get_credit());
                }
            }
        }
    }
}
void Application::rate_occupied_house(account::Member &current_member) {
    double rating_score = 0;
    double rating_score_occupied_house = 0;
    std::string comment, house_id;
    std::string requester_ID = current_member.get_id();
    int count = 0;
    bool back = false;
    std::cout << "Here's the information of your occupied house: \n";
    for (int a = 0; a < this->requests.size(); a++) {
        if (requester_ID == this->requests[a].getRequesterId() && !back) {
            for (int b = 0; b < this->houses.size(); b++) {
                if (this->houses[b].get_house_id() == this->requests[a].getHouseRequestedId() && this->requests[a].getRequestStatus() == "Accepted" && current_member.get_username() == this->requests[a].getRequesterUsername()) {
                    std::cout << "--> Owner: " << this->houses[b].getHouseOwner()
                              << " | City: " << this->houses[b].getCity()
                              << " | Credit per day: " << this->houses[b].get_credit()
                              << "\n\nDo you want to rate this house ?\n"
                              << "1. Yes\n"
                              << "2. No\n";
                    switch (Application::prompt_choice(1, 2)) {
                        case 1:
                            std::cout << "\nPlease enter the score you want to rate for this house <range: -10 to +10>: ";
                            std::cin >> rating_score_occupied_house;
                            std::cout << "\nPlease enter your comment about this house: ";
                            std::cin.ignore(256, '\n');
                            std::getline(std::cin, comment);
                            house_id = this->houses[b].get_house_id();
                            this->house_reviews.emplace_back(requester_ID, comment, rating_score_occupied_house, house_id);
                            for (auto house_review : this->house_reviews) {
                                if (house_review.getHouseId() == this->houses[b].get_house_id()) {
                                    rating_score += house_review.getRating();
                                    count++;
                                }
                            }
                            if (!back) {
                                double rating_score_final = rating_score / count;
                                std::cout << rating_score_final << "\n";
                                std::stringstream sts;
                                sts << std::fixed << std::setprecision(1) << rating_score_final;
                                sts >> rating_score_final;
                                for (int i = 0; i < this->houses.size(); i++) {
                                    for (auto house_review : this->house_reviews) {
                                        if (house_review.getHouseId() == this->houses[i].get_house_id()) {
                                            this->houses[i].setRatingScore(rating_score_final);
                                        }
                                    }
                                }
                                break;
                            }
                        case 2:
                            back = true;
                            break;
                    }
                }
            }
        }
    }
}

void Application::rate_occupier(account::Member &current_member) {
    double rating_score = 0;
    double rating_score_occupier = 0;
    std::string comment, occupier_id;
    std::string reviewer_ID = current_member.get_id();
    int count = 0;
    bool back = false;
    std::vector<account::OccupantReview> occupant_list;
    std::cout << "Here is the information for the current user of your home: \n";
    for (auto occupant : occupant_reviews) {
        std::string occupierID = occupant.getOccupierId();
        for (auto member : members) {
            if (member.get_id() == occupierID && reviewer_ID == occupant.getReviewerId()) {
                occupant_list.emplace_back(occupant);
                std::cout << "--> Username: " << member.get_username()
                          << " | Firstname: " << member.get_first_name()
                          << " | Lastname: " << member.get_last_name()
                          << " | Phone number: " << member.get_phone_number()
                          << "\n\nDo you want to rate this user ?\n"
                          << "1. Yes\n"
                          << "2. No\n";
                switch (Application::prompt_choice(1, 2)) {
                    case 1:
                        std::cout << "\nPlease enter the score you want to rate for this user <range: -10 to +10>: ";
                        std::cin >> rating_score_occupier;
                        std::cout << "\nPlease enter your comment about this user: ";
                        std::cin.ignore(256, '\n');
                        std::getline(std::cin, comment);
                        occupier_id = member.get_id();
                        this->occupant_reviews.emplace_back(reviewer_ID, comment, rating_score_occupier, occupier_id);
                        for (auto occupant_review : this->occupant_reviews) {
                            if (occupant_review.getOccupierId() == member.get_id()) {
                                rating_score += occupant_review.getRating();
                                count++;
                            }
                        }
                        if (!back) {
                            double rating_score_final = rating_score / count;
                            std::stringstream sts;
                            sts << std::fixed << std::setprecision(1) << rating_score_final;
                            sts >> rating_score_final;
                            for (int i = 0; i < this->members.size(); i++) {
                                for (auto occupant_review : this->occupant_reviews) {
                                    if (occupant_review.getOccupierId() == this->members[i].get_id()) {
                                        this->members[i].setRatingScore(rating_score_final);
                                    }
                                }
                            }
                        }
                    case 2:
                        back = true;
                        break;
                }
            }
        }
    }
    if (occupant_list.empty() || occupant_reviews.empty()) {
        std::cout << "\nThere is no one occupying your house right now!\n";
    }
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
                     "5. View incoming requests to your listing house. \n"
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
                          << "Rating: " << std::fixed << std::setprecision(1) << current_member->getRatingScore() << "\n\n";
                break;
            case 2:
                Application::add_house(*current_member);
                break;
            case 3:
                Application::list_house_available(*current_member);
                break;
            case 4:
                temp_vector = Application::list_house_available(*current_member);
                if (Application::request_house_to_occupy(*current_member, temp_vector))
                    break;
            case 5:
                Application::check_house_request_list(*current_member);
                break;
            case 6:
                Application::rate_occupied_house(*current_member);
                break;
            case 7:
                Application::rate_occupier(*current_member);
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
