#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_

#include <ctime>
#include "Datetime.h"
#include "Duration.h"

namespace utils {
    namespace time {

        class Period {
          private:
            Datetime start, end;

          public:
            Period();
            explicit Period(const Datetime &datetime1, const Datetime &datetime2 = Datetime());

            ~Period() = default;
            Period(const Period &source) = default;
            Period(Period &&source) = default;
            Period &operator=(const Period &source) = default;
            Period &operator=(Period &&source) = default;

            Datetime get_start();
            Period &set_start(const Datetime &start);
            Datetime get_end();
            Period &set_end(const Datetime &end);

            Duration get_duration() const;

            unsigned long long seconds();
            unsigned long long minutes();
            unsigned long long hours();
            unsigned long long days();
        };

    } // time
} // duration

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_
