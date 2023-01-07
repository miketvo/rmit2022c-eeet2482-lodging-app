#include "Admin.h"

namespace account {

    Admin::Admin(const std::string &password) : Account("admin", "admin", password) {}

} // account