#include "Admin.h"

namespace account {

    Admin::Admin(const std::string &password) : Account("admin", "admin", password) {}

    std::map<std::string, std::string> Admin::to_map() {
       return this->Account::to_map();
    }

} // account