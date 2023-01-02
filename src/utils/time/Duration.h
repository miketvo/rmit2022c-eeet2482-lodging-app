#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_

#include <ctime>
#include "Datetime.h"
#include "Temporal.h"

namespace utils {
    namespace time {

        class Datetime;

        class Duration : public Temporal {
          public:
            explicit Duration(unsigned days = 0, unsigned hours = 0, unsigned minutes = 0, unsigned seconds = 0);
            explicit Duration(const Datetime &datetime1, const Datetime &datetime2);

            unsigned long long seconds();
            unsigned long long minutes();
            unsigned long long hours();
            unsigned long long days();

            double to_seconds();
            double to_minutes();
            double to_hours();
            double to_days();

            Duration operator-(const Duration &duration);
            Duration operator-=(const Duration &duration);

            Duration operator*(unsigned val);
            Duration operator*=(unsigned val);
            Duration operator/(unsigned val);
            Duration operator/=(unsigned val);

            friend Datetime;
        };

    } // time
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_
