#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_

#include <map>
#include <string>

namespace utils {

    class Review {
      private:
        std::string id;
        std::string comment;
        short rating;

      public:
        Review(std::string id = "", std::string comment = "", short rating = 0);

        virtual std::map<std::string, std::string> to_map();
    };

} // utils


#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_