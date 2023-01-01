#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_

#include <ctime>
#include "Datetime.h"

namespace utils {
    namespace time {

        class Period {
          private:
            Datetime start, end;

          public:
            Period();
            explicit Period(Datetime datetime1, Datetime datetime2 = Datetime());

            ~Period() = default;
            Period(const Period &source) = default;
            Period(Period &&source) = default;
            Period &operator=(const Period &source) = default;
            Period &operator=(Period &&source) = default;

            unsigned long long seconds();
            unsigned long long minutes();
            unsigned long long hours();
            unsigned long long m_day();
            unsigned long long month();
            unsigned long long year();
            unsigned long long w_day();
            unsigned long long y_day();
            std::string strf(const char *fmt);

            Datetime get_start();
            void set_start(Datetime start);
            Datetime get_end();
            void set_end(Datetime end);

            operator Duration() const;
        };

    } // time
} // duration

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_PERIOD_H_
