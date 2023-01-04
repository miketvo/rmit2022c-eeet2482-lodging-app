#include <iostream>
#include <algorithm>
#include "Period.h"

namespace utils {
    namespace time {
        Period::Period() {
            this->start = new Datetime();
            this->end = new Datetime();
        }

        Period::Period(const Datetime &datetime1, const Datetime &datetime2) : Period() {
            if (datetime1 > datetime2) {
                *this->start = datetime2;
                *this->end = datetime1;
            }
            *this->start = datetime1;
            *this->end = datetime2;
        }


        Period::~Period() {
            delete this->start;
            delete this->end;
        }

        Period::Period(const Period &source) : Period() {
            *this->start = *source.start;
            *this->end = *source.end;
        }

        Period::Period(Period &&source) noexcept : Period() {
            swap(*this, source);
        }

        Period &Period::operator=(const Period &source) {
            if (this != &source) {
                *this->start = *source.start;
                *this->end = *source.end;
            }
            return *this;
        }

        Period &Period::operator=(Period &&source) noexcept {
            swap(*this, source);
            return *this;
        }



        Datetime Period::get_start() {
            return *this->start;
        }

        Period &Period::set_start(const Datetime &start) {
            *this->start = start;
            return *this;
        }

        Datetime Period::get_end() {
            return *this->end;
        }

        Period &Period::set_end(const Datetime &end) {
            *this->end = end;
            return *this;
        }


        Duration Period::duration() const {
            return Duration(*this->start, *this->end);
        }


        unsigned long long Period::seconds() const {
            return this->duration().seconds();
        }

        unsigned long long Period::minutes() const {
            return this->duration().minutes();
        }

        unsigned long long Period::hours() const {
            return this->duration().hours();
        }

        unsigned long long Period::days() const {
            return this->duration().days();
        }

        void swap(Period a, Period b) {
            std::swap(a.start, b.start);
            std::swap(a.end, b.end);
        }
    } // time
} // utils