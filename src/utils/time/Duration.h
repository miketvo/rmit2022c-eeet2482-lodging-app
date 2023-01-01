#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_

#include <ctime>
#include "Temporal.h"
#include "Datetime.h"

namespace utils {
    namespace time {

        class Duration : public Temporal {
          public:
            explicit Duration(unsigned days = 0, unsigned hours = 0, unsigned minutes = 0, unsigned seconds = 0);
            explicit Duration(const Datetime &datetime1, const Datetime &datetime2 = Datetime());

            unsigned long long seconds();
            unsigned long long minutes();
            unsigned long long hours();
            unsigned long long days();
        };

    } // time
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_
