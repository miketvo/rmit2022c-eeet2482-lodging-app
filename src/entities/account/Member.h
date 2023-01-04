#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_MEMBER_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_MEMBER_H_

#include <iostream>
#include <vector>
#include "Account.h"
#include "../House.h"

namespace account {

    class Member : public Account {
      private:
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        unsigned credits;
        House *house;

      public:
        Member(const std::string &id, const std::string &username, const std::string &password);

        Member(const std::string &id_1,
               const std::string &username_1,
               const std::string &password_1,
               const std::string &id,
               const std::string &username,
               const std::string &password,
               const std::string &first_name,
               const std::string &last_name,
               const std::string &phone_number,
               unsigned int credits,
               House *house);

        std::map<std::string, std::string> to_map() override;
    };

} // account

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_MEMBER_H_
