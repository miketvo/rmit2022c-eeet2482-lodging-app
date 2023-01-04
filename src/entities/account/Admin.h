#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ADMIN_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ADMIN_H_

#include <map>
#include <string>
#include "Account.h"

namespace account {

    class Admin : public Account {
      private:
      public:
        Admin();

        std::map<std::string, std::string> to_map() override;
    };

} // account

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_ADMIN_H_
