#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_

#include <ctime>
#include "Duration.h"

namespace utils {
    namespace time {

        class Datetime;
        class Duration;

        class Period {
          private:
            Datetime *start, *end;

          public:
            Period();
            explicit Period(const Datetime &datetime1, const Datetime &datetime2);

            ~Period();
            Period(const Period &source);
            Period(Period &&source) noexcept;
            Period &operator=(const Period &source);
            Period &operator=(Period &&source) noexcept;

            Datetime get_start();
            Period &set_start(const Datetime &start);
            Datetime get_end();
            Period &set_end(const Datetime &end);

            Duration duration() const;

            unsigned long long seconds() const;
            unsigned long long minutes() const;
            unsigned long long hours() const;
            unsigned long long days() const;
        };

    } // time
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_
