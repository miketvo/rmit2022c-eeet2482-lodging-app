#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ACCOUNT_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ACCOUNT_H_

#include "map"
#include "string"
#include "vector"

namespace account {

    class Account {
      protected:
        std::string username;
        std::string password;

      public:
        Account();
        Account(const std::string &username, const std::string &password);

        std::string get_username() const;

        bool authenticate(const std::string &pwd) const;

        virtual void from_map(std::map<std::string, std::string> map);
        virtual std::map<std::string, std::string> to_map();
    };

} // account

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ACCOUNT_H_
