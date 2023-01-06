#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_

#include <iostream>

#include "Member.h"

namespace utils {
    class Review;
}

namespace account {
    class Member;
    class OccupantReview : public utils::Review {
      private:
        Member *reviewee;

      public:
        OccupantReview() = default;
        OccupantReview(const std::string &id, const std::string &comment, short rating);

        std::map<std::string, std::string> to_map();

        friend class Member;
    };

}// namespace account

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_