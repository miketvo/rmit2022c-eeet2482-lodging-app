#include <cstring>
#include "corrupted_database.h"

namespace utils {
    namespace io {
        namespace exceptions {
            corrupted_database::corrupted_database(const std::string &message) noexcept: runtime_error(this->message) {
                if (!message.empty()) this->message += ": " + message;
            }

            corrupted_database::corrupted_database(const char *const message) noexcept: runtime_error(this->message) {
                if (std::strlen(message)) {
                    this->message += ": ";
                    this->message += message;
                }
            }

            char const *corrupted_database::what() const noexcept {
                return this->message.c_str();
            }
        } // exceptions
    } // io
} // utils