#include <iostream>
#include <sys/stat.h>
#include <iomanip>
#include "Application.h"
#include "utils/io/DatabaseFile.h"
#include "entities/account/Admin.h"

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
}

void Application::load_database() {
    std::vector<std::map<std::string, std::string>> data;
    data.clear();

    utils::io::DatabaseFile admin_dtb(this->database_path + "admin.dat");
    admin_dtb.read();
    this->admin.from_map(admin_dtb[0]);

    utils::io::DatabaseFile members_dtb(this->database_path + "members.dat");
    members_dtb.read();
    members_dtb >> data;
    for (auto& record : data) {
        std::cout << record["username"];
        this->members.emplace_back();
        this->members.back().from_map(record);
    }
//
//    file.read(this->database_path + "houses.dat");
//    file >> data;
//
//    file.read(this->database_path + "requests.dat");
//    file >> data;
//
//    file.read(this->database_path + "house_reviews.dat");
//    file >> data;
//
//    file.read(this->database_path + "occupant_reviews.dat");
//    file >> data;
//
//    file.read(this->database_path + "cities.dat");
//    file >> data;
}

void Application::save_database() {

}

void Application::reset_database() {
    // TODO: Implement this
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
                // todo list house details
                std::cout << "House details \n";
                break;
            case 2:
                // todo register accout
                std::cout << "Registered...\n";
                break;
            case 0:
                back = true;
                break;
        }
    }
}

void Application::member_menu() {
    bool back = true;
    std::string buffer;
    account::Member *current_member;

    std::cout << "Enter your username: ";
    std::getline(std::cin, buffer);
    for (auto& member : this->members) {
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
                     "2. List all house are available to be occupied.\n"
                     "3. Search all available houses. \n"
                     "4. Request house to occupy. \n"
                     "5. Accept/Decline incoming requests. \n"
                     "6. Rate occupied house. \n"
                     "7. Rate occupiers who had used my house. \n";

        switch (Application::prompt_choice(1, 3)) {
            case 1:
                std::cout <<
                          "\nUsername: " << current_member->get_username() << "\n"
                          "First name: " << current_member->get_first_name() << "\n" <<
                          "Last name: " << current_member->get_last_name() << "\n" <<
                          "Phone number: " << current_member->get_phone_number() << "\n" <<
                          "Credits: " << current_member->get_credits() << "\n" <<
                          "Rating: " << std::fixed << std::setprecision(1) << current_member->get_rating() << "\n\n";
                break;
            case 2:
                // todo register accout
                break;
            case 3:
                // todo Search all available houses
                break;
            case 4:
                // todo Request house to occupy
                break;
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
                    // todo View all house details and member details
                    break;
                case 0:back = true;
                    break;
            }
        }
    }
}

bool Application::register_member() {
    std::string username, password, first_name, last_name, phone_number;

    std::cout << "Enter your new username: ";
    std::getline(std::cin, username);
    std::cout << "Enter your new password: ";
    std::getline(std::cin, password);

    for (const auto& member : this->members) {
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

    this->members.emplace_back(username, password, first_name, last_name, phone_number);
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
    std::cout <<
              "======================================\n" <<
              "EEET2482/COSC2082 ASSIGNMENT\n" <<
              "VACATION HOUSE EXCHANGE APPLICATION\n" <<
              "\n" <<
              "Instructors: Mr. Linh Tran & Phong Ngo\n" <<
              "Group: Group 9\n" <<
              "s3963207, Do Le long An\n" <<
              "s3817747, Hoang Ngoc Duan\n" <<
              "s3941773, Nguyen Phuong Nam\n" <<
              "s3877562, Vo Tuong Minh" <<
              "\n======================================\n\n";

    if (!this->detected_database()) {
        this->init_database();
    }
    this->load_database();

    // Main application loop
    while (!this->quit) {
        std::cout <<
                  "\nMAIN MENU\n" <<
                  "=========================\n" <<
                  "--> 0. Exit\n" <<
                  "--> 1. Login as Guest\n" <<
                  "--> 2. Login as existing Member\n" <<
                  "--> 3. Register as new Member\n" <<
                  "--> 4. Login as Admin\n" <<
                  "--> 5. Reset application\n";

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
