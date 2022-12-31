#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_CORRUPTED_DATABASE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_CORRUPTED_DATABASE_H_

#include <stdexcept>

namespace utils {
    namespace exceptions {

      class corrupted_database : public std::runtime_error {
        private:
          std::string message = "Corrupted database";

        public:
          explicit corrupted_database(const std::string &message = "") noexcept;
          explicit corrupted_database(char const *message) noexcept;

          char const *what() const noexcept override;
      };

    } // utils
} // exceptions

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_CORRUPTED_DATABASE_H_
