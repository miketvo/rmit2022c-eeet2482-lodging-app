#include "Period.h"

namespace utils {
    namespace time {
        Period::Period() {
            this->start = Datetime();
            this->end = Datetime();
        }

        Period::Period(const Datetime &datetime1, const Datetime &datetime2) {
            if (datetime1 > datetime2) {
                this->start = datetime2;
                this->end = datetime1;
            }
            this->start = datetime1;
            this->end = datetime2;
        }


        Datetime Period::get_start() {
            return this->start;
        }

        Period &Period::set_start(const Datetime &start) {
            this->start = start;
            return *this;
        }

        Datetime Period::get_end() {
            return this->end;
        }

        Period &Period::set_end(const Datetime &end) {
            this->end = end;
            return *this;
        }


        Duration Period::get_duration() const {
            return Duration();  // TODO: Implement
        }


        unsigned long long Period::seconds() {
            return this->get_duration().seconds();
        }

        unsigned long long Period::minutes() {
            return this->get_duration().minutes();
        }

        unsigned long long Period::hours() {
            return this->get_duration().hours();
        }

        unsigned long long Period::days() {
            return this->get_duration().days();
        }
    } // time
} // utils