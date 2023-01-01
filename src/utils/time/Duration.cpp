#include "Duration.h"

namespace utils {
    namespace time {
        Duration::Duration(unsigned int days, unsigned int hours, unsigned int minutes, unsigned int seconds) {
            this->Temporal::time = new std::time_t;
            *this->Temporal::time = seconds + 60 * minutes + 60 * 60 * hours + 24 * 60 * 60 * days;
        }

        Duration::Duration(const Datetime &datetime1, const Datetime &datetime2) {
            this->Temporal::time = new std::time_t;
            *this->Temporal::time = datetime1.get() - datetime2.get();
        }


        unsigned long long Duration::seconds() {
            return *this->Temporal::time % 60;
        }

        unsigned long long Duration::minutes() {
            return *this->Temporal::time % (60 * 60);
        }

        unsigned long long Duration::hours() {
            return *this->Temporal::time % (24 * 60 * 60);
        }

        unsigned long long Duration::days() {
            return *this->Temporal::time / (24 * 60 * 60);
        }
    } // time
} // utils