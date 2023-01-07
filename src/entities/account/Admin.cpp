#include "Admin.h"

namespace account {

    Admin::Admin() : Account("admin", "admin", "") {}

    Admin::Admin(const std::string &password) : Account("admin", "admin", password) {}

} // account