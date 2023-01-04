#include <iostream>
#include "Application.h"


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
