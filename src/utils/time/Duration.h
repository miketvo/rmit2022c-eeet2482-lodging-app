#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_

#include <ctime>
#include "Temporal.h"
#include "Datetime.h"

namespace utils {
    namespace time {

        class Duration : protected Temporal {
          public:
            Duration();
            Duration(Datetime datetime1, Datetime datetime2);
            Duration(Period period);
        };

    } // time
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DURATION_H_
