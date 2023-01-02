#include <algorithm>
#include "Temporal.h"

namespace utils {
    namespace time {
        Temporal::Temporal() {
            this->time = new std::time_t;
        }

        Temporal::Temporal(std::time_t time) : Temporal() {
            *this->time = time;
        }


        Temporal::~Temporal() {
            delete this->time;
        }

        Temporal::Temporal(const Temporal &source) : Temporal() {
            *this->time = *source.time;
        }

        Temporal::Temporal(Temporal &&source) noexcept : Temporal() {
            swap(*this, source);
        }

        Temporal &Temporal::operator=(const Temporal &source) {
            swap(*this, source);
            return *this;
        }

        Temporal &Temporal::operator=(Temporal &&source) noexcept {
            swap(*this, source);
            return *this;
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


        void swap(Temporal a, Temporal b) {
            std::swap(a.time, b.time);
        }
    } // time
} // utils