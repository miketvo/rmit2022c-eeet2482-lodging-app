#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DATETIME_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DATETIME_H_

#include <ctime>
#include <string>
#include "Temporal.h"
#include "Duration.h"
#include "Period.h"

namespace utils {
    namespace time {

        class Datetime : protected Temporal {
          public:
            Datetime();
            Datetime(std::time_t time);
            Datetime(std::tm time);
            Datetime(const std::string &time_str, const char *fmt);

            Period operator-(const Datetime &datetime);
            static Period between(const Datetime &datetime1, const Datetime &datetime2);
        };

    } // time
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_DATETIME_H_
