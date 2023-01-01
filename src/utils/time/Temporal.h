#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_TEMPORAL_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_TEMPORAL_H_

#include <ctime>
#include <string>

namespace utils {
    namespace time {

        class Temporal {
          protected:
            std::time_t *time;

            Temporal();
            Temporal(std::time_t time);
            Temporal(std::tm time);
            Temporal(const std::string &time_str, const char *fmt);

            ~Temporal();
            Temporal(const Temporal &source) = default;
            Temporal(Temporal &&source) = default;
            Temporal &operator=(const Temporal &source) = default;
            Temporal &operator=(Temporal &&source) = default;

            int seconds();
            int minutes();
            int hours();
            int m_day();
            int month();
            int year();
            int w_day();
            int y_day();
            int is_dst();
            std::string strf(const char *fmt);

            void set(std::time_t time);
            void set(std::tm time);
            void set(std::string &time_str);

            Temporal operator+(const Temporal &temporal);
            Temporal operator+=(const Temporal &temporal);
            Temporal operator-(const Temporal &temporal);
            Temporal operator-=(const Temporal &temporal);

            bool operator>(const Temporal &temporal);
            bool operator<(const Temporal &temporal);
            bool operator==(const Temporal &temporal);
            bool operator!=(const Temporal &temporal);
            bool operator>=(const Temporal &temporal);
            bool operator<=(const Temporal &temporal);
        };

    } // time
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_TEMPORAL_H_
