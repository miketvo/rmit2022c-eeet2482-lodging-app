#include "Member.h"

namespace account {

    Member::Member(
        const std::string &id,
        const std::string &username,
        const std::string &password)
        : Account(id, username, password) {
        // TODO: Implement this
    }

    Member::Member(const std::string &id_1,
                   const std::string &username_1,
                   const std::string &password_1,
                   const std::string &id,
                   const std::string &username,
                   const std::string &password,
                   const std::string &first_name,
                   const std::string &last_name,
                   const std::string &phone_number,
                   unsigned int credits,
                   House *house)
                   : Account(id_1, username_1, password_1) {
        // TODO: Implement this
    }
} // account
