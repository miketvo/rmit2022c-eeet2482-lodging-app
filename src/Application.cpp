#if defined(_WIN32)
#define PLATFORM_DECTECTED
#define OS_WINDOWS
#else
#define PLATFORM_DECTECTED
#define OS_UNIX
#endif
#ifndef PLATFORM_DECTECTED
#error Could not detect operating system platform
#endif

#ifdef OS_UNIX
namespace fs = std::__fs::filesystem;
#endif
#ifdef OS_WINDOWS
namespace fs = std::filesystem;
#endif

#include <iostream>
#include "Application.h"
#include "utils/io/DatabaseFile.h"
#include <filesystem>
#include <fstream>
#include <string>

void Application::init_database() {
#ifdef OS_UNIX
    fs::path osUnix = "~/.lodging/";
    if(!fs::is_directory(osUnix)) {
        std::cout << "this path found";
    } else {
        std::cout << "this path not found";
    }
#endif
#ifdef OS_WINDOWS
    fs::path osWin = "~/AppData/Local/lodging/";
    if (fs::is_directory(osWin)) {
        std::cout << "this path found";
    } else {
        std::cout << "this path not found";
    }
#endif

}

void Application::load_database() {
#ifdef OS_UNIX
    this->database_path = "~/.lodging/";
    std::cout << database_path;
#endif
#ifdef OS_WINDOWS
    this->database_path = "~/AppData/Local/lodging/";
#endif
    utils::DatabaseFile databaseFile(this->database_path + "houses.dat");

}

void Application::save_database() {

}

void Application::reset_database() {

}

bool Application::login(Account account) {
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

void Application::unregister_member(Member member) {

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
    std::cout << "s3963207, Do Le long An" << "\n";
    std::cout << "s3963207, Do Le long An" << "\n";
    std::cout << "s3963207, Do Le long An" << "\n\n";

    Application::init_database();
    Application::load_database();
}
