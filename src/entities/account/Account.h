#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ACCOUNT_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ACCOUNT_H_

#include "map"
#include "string"
#include "vector"

namespace account {

    class Account {
      protected:
        std::string id;
        std::string username;
        std::string password;

      public:
        Account();
        Account(const std::string &id, const std::string &username, const std::string &password);

        bool authenticate(const std::string &pwd);

        virtual std::map<std::string, std::string> to_map();
    };

} // account

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ACCOUNT_H_
