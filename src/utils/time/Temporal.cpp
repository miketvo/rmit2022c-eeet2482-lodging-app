#include "Temporal.h"

namespace utils {
    namespace time {
        Temporal::Temporal() {
            this->time = new std::time_t;
            std::time(this->time);
        }

        Temporal::Temporal(std::time_t time) {
            this->time = new std::time_t;
            *this->time = time;
        }


        Temporal::~Temporal() {
            delete this->time;
        }


        void Temporal::set(std::time_t time) {
            *this->time = time;
        }


        Temporal Temporal::operator+(const Temporal &temporal) {
            return Temporal(*this->time + *temporal.time);
        }

        Temporal Temporal::operator+=(const Temporal &temporal) {
            *this->time += *temporal.time;
            return Temporal(*this->time);
        }

        Temporal Temporal::operator-(const Temporal &temporal) {
            return Temporal(*this->time - *temporal.time);
        }

        Temporal Temporal::operator-=(const Temporal &temporal) {
            *this->time -= *temporal.time;
            return Temporal(*this->time);
        }


        bool Temporal::operator>(const Temporal &temporal) const {
            return *this->time > *temporal.time;
        }

        bool Temporal::operator<(const Temporal &temporal) const {
            return *this->time < *temporal.time;
        }

        bool Temporal::operator==(const Temporal &temporal) const {
            return *this->time == *temporal.time;
        }

        bool Temporal::operator!=(const Temporal &temporal) const {
            return *this->time != *temporal.time;
        }

        bool Temporal::operator>=(const Temporal &temporal) const {
            return *this->time >= *temporal.time;
        }

        bool Temporal::operator<=(const Temporal &temporal) const {
            return *this->time <= *temporal.time;
        }
    } // time
} // utils