#include "Application.h"
#include "entities/account/Admin.h"
#include "utils/io/DatabaseFile.h"
#include <iostream>
#include <string>

void Application::init_database() {
}

void Application::load_database() {
#ifdef OS_UNIX
    this->database_path = "~/.lodging/";
    std::cout << database_path;
#endif
#ifdef OS_WINDOWS
    this->database_path = "~/AppData/Local/lodging/";
#endif
    utils::io::DatabaseFile databaseFile(this->database_path + "houses.dat");
}

void Application::save_database() {
}

void Application::reset_database() {
}

bool Application::login(account::Account account) {
    return false;
}

void Application::guest_menu() {
    while (1) {
        std::cout << "\n This is your menu:\n"
                     "1. View all house details.\n"
                     "2. Register as member account.\n"
                     "3. Exit.\n"
                     "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                // todo list house details
                std::cout << "House details \n";
                break;
            case 2:
                // todo register accout
                std::cout << "Registered...\n";
                break;
            case 3:
                return;
        }
        break;
    }
}

void Application::member_menu() {
    std::cout << "Enter password: ";
    std::string password;
    getline(std::cin, password);
    while (password == "password") {
        std::cout << "\n This is your menu:\n"
                     "1. View information.\n"
                     "2. List all house are available to be occupied.\n"
                     "3. Search all available houses. \n"
                     "4. Request house to occupy. \n"
                     "5. Accept/Decline incoming requests. \n"
                     "6. Rate occupied house. \n"
                     "7. Rate occupiers who had used my house. \n"
                     "8. Exit. \n"
                     "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                // todo list house details
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
            case 8:
                return;
                break;
        }
        break;
    }
}

void Application::admin_menu() {
    while (1) {
        std::cout << "\n This is your menu:\n"
                     "1. View all house details and member details.\n"
                     "2. Exit.\n"
                     "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                // todo View all house details and member details
                break;
            case 2:
                return;
        }
        break;
    }
}

bool Application::register_member() {
    return false;
}

void Application::unregister_member(const account::Member &member) {
}

Application::Application() {
    this->quit = false;
    this->database_path = "";
    this->login_type = GUEST;
}

Application::Application(const std::string &database_path) {
    this->quit = false;
    this->database_path = database_path;
    this->login_type = GUEST;
}

void Application::main_loop() {
    std::string buffer;

    std::cout << "EEET2482/COSC2082 ASSIGNMENT"
              << "\n";
    std::cout << "VACATION HOUSE EXCHANGE APPLICATION"
              << "\n\n";
    std::cout << "Instructors: Mr. Linh Tran & Phong Ngo"
              << "\n";
    std::cout << "Group: Group 9"
              << "\n";
    std::cout << "s3963207, Do Le long An"
              << "\n";
    std::cout << "s3963207, Do Le long An"
              << "\n";
    std::cout << "s3963207, Do Le long An"
              << "\n";
    std::cout << "s3963207, Do Le long An"
              << "\n\n";

    while (1) {
        std::cout << "Use the app as: "
                  << " 1. Guest "
                  << " 2. Member "
                  << " 3. Admin\n";
        std::cout << "Enter your choice: ";
        std::getline(std::cin, buffer);
        int choice = std::stoi(buffer);

        switch (choice) {
            case 1:
                Application::guest_menu();
                break;
            case 2:
                Application::member_menu();
                break;
            case 3:
                Application::admin_menu();
                break;
            default:
                break;
        }
        break;
    }

    Application::init_database();
    Application::load_database();
}
