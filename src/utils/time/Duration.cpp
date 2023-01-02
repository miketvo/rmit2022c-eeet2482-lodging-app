#include <stdexcept>
#include "Duration.h"

namespace utils {
    namespace time {
        Duration::Duration(unsigned int days, unsigned int hours, unsigned int minutes, unsigned int seconds) : Temporal() {
            *this->Temporal::time = seconds + 60 * minutes + 60 * 60 * hours + 24 * 60 * 60 * days;
        }

        Duration::Duration(const Datetime &datetime1, const Datetime &datetime2) : Temporal() {
            *this->Temporal::time = *datetime1.time - *datetime2.time;
        }


        unsigned long long Duration::seconds() {
            return *this->Temporal::time % 60;
        }

        unsigned long long Duration::minutes() {
            return (*this->Temporal::time - this->seconds()) / 60;
        }

        unsigned long long Duration::hours() {
            return (*this->Temporal::time - this->seconds() - this->minutes() * 60) / 3600;
        }

        unsigned long long Duration::days() {
            return *this->Temporal::time / 86400;
        }


        double Duration::to_seconds() {
            return static_cast<double>(*this->Temporal::time);
        }

        double Duration::to_minutes() {
            return this->to_seconds() / 60;
        }

        double Duration::to_hours() {
            return this->to_minutes() / 60;
        }

        double Duration::to_days() {
            return this->to_hours() / 24;
        }
    } // time
} // utils