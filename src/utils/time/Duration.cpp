#include "Duration.h"

namespace utils {
    namespace time {
        Duration::Duration(unsigned int days, unsigned int hours, unsigned int minutes, unsigned int seconds) : Temporal() {
            *this->Temporal::time = seconds + 60 * minutes + 60 * 60 * hours + 24 * 60 * 60 * days;
        }

        Duration::Duration(const Datetime &datetime1, const Datetime &datetime2) : Temporal() {
            *this->Temporal::time = std::abs(*datetime1.time - *datetime2.time);
        }


        unsigned long long Duration::seconds() {
            return *this->Temporal::time % 60;
        }

        unsigned long long Duration::minutes() {
            return (*this->Temporal::time - this->seconds() - this->hours() * 3600 - this->days() * 86400) / 60;
        }

        unsigned long long Duration::hours() {
            return (*this->Temporal::time - this->seconds() - this->days() * 86400) / 3600;
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


        Duration Duration::operator*(unsigned int val) {
            return Duration(0, 0, 0, *this->time * val);
        }

        Duration Duration::operator*=(unsigned int val) {
            *this->time *= val;
            return Duration(0, 0, 0, *this->time * val);
        }

        Duration Duration::operator/(unsigned int val) {
            return Duration(0, 0, 0, *this->time / val);
        }

        Duration Duration::operator/=(unsigned int val) {
            *this->time /= val;
            return Duration(0, 0, 0, *this->time / val);
        }
    } // time
} // utils