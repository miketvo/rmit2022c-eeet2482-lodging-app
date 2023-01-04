#include "Account.h"


Entity::Account::Account(long long int id, const std::string &username, const std::string &password) : id(id), username(username), password(password) {
    this->id = std::move(id);
    this->username = std::move(username);
    this->password = std::move(password);
}
