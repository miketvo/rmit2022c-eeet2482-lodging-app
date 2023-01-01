#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_TEMPORAL_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_TEMPORAL_H_

#include <ctime>

namespace utils {
    namespace time {

        class Temporal {
          protected:
            std::time_t *time;

            Temporal();
            explicit Temporal(std::time_t time);

          public:
            ~Temporal();
            Temporal(const Temporal &source) = default;
            Temporal(Temporal &&source) = default;
            Temporal &operator=(const Temporal &source) = default;
            Temporal &operator=(Temporal &&source) = default;

            void set(std::time_t time);

            Temporal operator+(const Temporal &temporal);
            Temporal operator+=(const Temporal &temporal);
            Temporal operator-(const Temporal &temporal);
            Temporal operator-=(const Temporal &temporal);

            bool operator>(const Temporal &temporal) const;
            bool operator<(const Temporal &temporal) const;
            bool operator==(const Temporal &temporal) const;
            bool operator!=(const Temporal &temporal) const;
            bool operator>=(const Temporal &temporal) const;
            bool operator<=(const Temporal &temporal) const;
        };

    } // time
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_TIME_TEMPORAL_H_
