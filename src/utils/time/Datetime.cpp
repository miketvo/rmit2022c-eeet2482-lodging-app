#include <iomanip>
#include <sstream>
#include "Datetime.h"

namespace utils {
    namespace time {
        Datetime::Datetime() : Temporal() {}

        Datetime::Datetime(std::time_t time) : Temporal(time) {}

        Datetime::Datetime(const std::tm &time) : Temporal() {
            auto *temp = new std::tm;
            *temp = time;
            *this->time = std::mktime(temp);
            delete temp;
        }

        Datetime::Datetime(const std::string &time_str, const char *fmt) : Temporal() {
            auto *temp = new std::tm;
            std::stringstream buffer;

            buffer << time_str;
            buffer >> std::get_time(temp, fmt);
            *this->time = std::mktime(temp);

            delete temp;
        }

        int Datetime::second() {
            return localtime(this->time)->tm_sec;
        }

        int Datetime::minute() {
            return localtime(this->time)->tm_min;
        }

        int Datetime::hour() {
            return localtime(this->time)->tm_hour;
        }

        int Datetime::m_day() {
            return localtime(this->time)->tm_mday;
        }

        int Datetime::month() {
            return localtime(this->time)->tm_mon + 1;
        }

        int Datetime::year() {
            return localtime(this->time)->tm_year + 1900;
        }

        Weekdays Datetime::w_day() {
            return static_cast<Weekdays>(localtime(this->time)->tm_wday);
        }

        int Datetime::y_day() {
            return localtime(this->time)->tm_yday + 1;
        }

        int Datetime::dst() {
            return localtime(this->time)->tm_isdst;
        }

        std::string Datetime::strf(const char *fmt) {
            std::stringstream buffer;
            buffer << std::put_time(std::localtime(this->time), fmt);
            return buffer.str();
        }


        void Datetime::set(const std::tm &time) {
            auto *temp = new std::tm;
            *temp = time;
            *this->Temporal::time = mktime(temp);
            delete temp;
        }

        void Datetime::set(const std::string &time_str, const char *fmt) {
            auto *temp = new std::tm;
            std::stringstream buffer;

            buffer << time_str;
            buffer >> std::get_time(temp, fmt);
            *this->Temporal::time = mktime(temp);

            delete temp;
        }


        Datetime Datetime::operator+(const Duration &duration) {
            return Datetime(*this->time + *duration.time);
        }

        Datetime Datetime::operator+=(const Duration &duration) {
            *this->time += *duration.time;
            return Datetime(*this->time);
        }

        Datetime Datetime::operator-(const Duration &duration) {
            return Datetime(*this->time - *duration.time);
        }

        Datetime Datetime::operator-=(const Duration &duration) {
            *this->time -= *duration.time;
            return Datetime(*this->time);
        }


        Period Datetime::operator-(const Datetime &datetime) const {
            return Period().set_start(*this).set_end(datetime);
        }

        Period Datetime::between(const Datetime &datetime1, const Datetime &datetime2) {
            return datetime1 - datetime2;
        }

        std::time_t Datetime::now() {
            return std::time(nullptr);
        }
    } // time
} // utils