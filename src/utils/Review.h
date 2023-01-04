#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_

#include <map>
#include <string>
#include "../entities/account/Member.h"

namespace utils {

    class Review {
      protected:
        short rating;
        std::string id;
        std::string comment;
        account::Member *reviewer;

      public:
        explicit Review(const std::string &id = "", const std::string &comment = "", short rating = 0);

        virtual std::map<std::string, std::string> to_map();
    };

} // utils


#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_