#include <iostream>
#include "Account.h"

namespace account {

    Account::Account() {
        this->id = "";
        this->username = "";
        this->password = "";
    }

    Account::Account(const std::string &id, const std::string &username, const std::string &password) {
        this->id = id;
        this->username = username;
        this->password = password;
    }


    std::string Account::get_username() const {
        return this->username;
    }


    bool Account::authenticate(const std::string &pwd) const {
        return this->password == pwd;
    }


    void Account::from_map(std::map<std::string, std::string> map) {
        this->id = map["id"];
        this->username = map["username"];
        this->password = map["password"];
    }

    std::map<std::string, std::string> Account::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("id", this->id);
        map.emplace("username", this->username);
        map.emplace("password", this->password);
        return map;
    }
}// namespace account
