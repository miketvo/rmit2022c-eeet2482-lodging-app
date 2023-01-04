#include "Member.h"

namespace account {

    Member::Member(const std::string &id,
                   const std::string &username,
                   const std::string &password,
                   const std::string &first_name,
                   const std::string &last_name,
                   const std::string &phone_number,
                   unsigned int credits,
                   house::House *house)
                   : Account(id, username, password) {

    }

    std::map<std::string, std::string> Member::to_map() {
        return Account::to_map();
    }
} // account
