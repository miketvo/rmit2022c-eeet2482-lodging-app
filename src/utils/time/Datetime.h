#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DATETIME_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DATETIME_H_

#include <ctime>
#include <string>
#include "Temporal.h"
#include "Period.h"

namespace utils {
    namespace time {

        class Period;
        class Duration;

        enum Weekdays { SUN, MON, TUE, WED, THU, FRI, SAT };

        class Datetime : public Temporal {
          public:
            Datetime();
            explicit Datetime(std::time_t time);
            explicit Datetime(const std::tm &time);
            Datetime(const std::string &time_str, const char *fmt);

            int second();
            int minute();
            int hour();
            int m_day();
            int month();
            int year();
            Weekdays w_day();
            int y_day();
            int dst();
            std::string strf(const char *fmt);

            void set(const std::tm &time);
            void set(const std::string &time_str, const char *fmt);

            Datetime operator+(const Duration &duration);
            Datetime operator+=(const Duration &duration);
            Datetime operator-(const Duration &duration);
            Datetime operator-=(const Duration &duration);

            Period operator-(const Datetime &datetime) const;
            static Period between(const Datetime &datetime1, const Datetime &datetime2);

            static std::time_t now();
            friend Duration;
        };

    } // time
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DATETIME_H_
