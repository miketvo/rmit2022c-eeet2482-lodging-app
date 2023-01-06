#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_

#include "../entities/account/Member.h"
#include <map>
#include <string>

namespace account {
    class Member;
}
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

}// namespace utils

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_H_