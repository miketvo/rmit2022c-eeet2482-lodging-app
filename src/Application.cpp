#include <iostream>
#include "Application.h"
#include "utils/io/DatabaseFile.h"
#include "entities/account/Admin.h"
#include <sys/stat.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define PLATFORM_DETECTED 1
#include <windows.h>
#elif defined(__APPLE__) || defined(linux)
#define PLATFORM_DETECTED 1
#include <sys/ioctl.h>
#endif
#ifndef PLATFORM_DETECTED
#error Could not detect operating system platform
#endif

void Application::init_database() {
    struct stat sb;
#if defined(__APPLE__) || defined(linux)
    const char* dir = "~/.lodging/";
    if (stat(dir, &sb) == 0)
        std::cout << "The path is valid!";
    else
        std::errc::no_such_file_or_directory;
        std::cout << "The Path is invalid!" << std::endl;
#endif
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__CYGWIN__)
    const char* dir = "~/AppData/Local/lodging/";
    if (stat(dir, &sb) == 0)
        std::cout << "The path is valid!";
    else
        std::cout << "The Path is invalid!" std::endl;
#endif
}

void Application::load_database() {
#if defined(__APPLE__) || defined(linux)
    this->database_path = "~/.lodging/";
    std::cout << database_path;
#endif
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__CYGWIN__)
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

}

void Application::member_menu() {

}

void Application::admin_menu() {

}

bool Application::register_member() {
    return false;
}

void Application::unregister_member(const account::Member& member) {

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
    std::cout << "EEET2482/COSC2082 ASSIGNMENT" << "\n";
    std::cout << "VACATION HOUSE EXCHANGE APPLICATION" << "\n\n";
    std::cout << "Instructors: Mr. Linh Tran & Phong Ngo" << "\n";
    std::cout << "Group: Group 9" << "\n";
    std::cout << "s3963207, Do Le long An" << "\n";
    std::cout << "s3817747, Hoang Ngoc Duan" << "\n";
    std::cout << "s3941773, Nguyen Phuong Nam" << "\n";
    std::cout << "s3877562, Vo Tuong Minh" << "\n\n";

    Application::init_database();
    Application::load_database();

    // MAIN MENU
    std::cout << "* \t\t\t VACATION HOUSE EXCHANGE APPLICATION \t\t\t*\n\n" << std::endl;
    std::cout << "--> MAIN MENU\n\n";
    std::cout << "--> 1. Guest\n";
    std::cout << "--> 2. Admin\n";
    std::cout << "--> 3. Member\n";
    std::cout << "--> 4. Exit";


}
