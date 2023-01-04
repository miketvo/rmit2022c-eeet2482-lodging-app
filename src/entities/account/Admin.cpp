#include "Admin.h"

namespace account {

    std::map<std::string, std::string> Admin::to_map() {
        return Account::to_map();
    }

} // account