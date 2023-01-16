#include "Admin.h"

namespace account {

    Admin::Admin() : Account("admin", "") {}

    Admin::Admin(const std::string &password) : Account("admin", password) {}

} // account