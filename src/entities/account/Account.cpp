#include "Account.h"

namespace account {

    Account::Account(const std::string &id, const std::string &username, const std::string &password) {
        this->id = id;
        this->username = username;
        this->password = password;
    }


    std::map<std::string, std::string> Account::to_map() {
        return {};
    }

} // account
