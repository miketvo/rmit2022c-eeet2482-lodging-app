#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_H_

#include "iostream";
#include "map";
#include "string";
#include "vector";

namespace Entity {
    static long long id_count = 0;

    class Account {
      protected:
        long long id;
        std::string username;
        std::string password;

      public:
        Account(long long int id, const std::string &username, const std::string &password);
        void show_info();

    };

}// namespace Entity

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_H_
