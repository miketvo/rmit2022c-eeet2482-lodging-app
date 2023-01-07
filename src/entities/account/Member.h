#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_

#include "../../utils/Review.h"
#include "../../utils/time/Period.h"
#include "../house/House.h"
#include "Account.h"
#include "OccupantReview.h"
#include <iostream>
#include <vector>

namespace utils {
    namespace time {
        class Period;
    }
}// namespace utils
namespace house {
    class House;
}

namespace account {
    class OccupantReview;

    class Member : public Account {
      private:
        unsigned credits;
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        house::House *house;
        std::vector<OccupantReview *> reviews;

      public:
        Member();
        Member(
            const std::string &username,
            const std::string &password,
            const std::string &first_name,
            const std::string &last_name,
            const std::string &phone_number,
            unsigned int credits
        );

        //Function: Calculate the total rating score from occupant reviewers then get the average rating score
        //=> Get the Rating Score of Each Owner
        double getReviewRate();

        //Function: View the Member Info
        void viewInfo();

        //Function: List a House from the Owner
        void listHouse(utils::time::Period *start, utils::time::Period *end, unsigned int credits, double rating);

        //Function: Unlist the House from the list when the Owner doesn't want to
        bool unlistHouse();

        //Function: Get the available house lists
        void availableHouse();

        //Function: Get the available request from own House
        void listRequest();

        //Function: Accept the request from the Occupier
        bool acceptRequest();// Need requestID => Request Class

        //Function: Reject the request from the Occupier
        bool rejectRequest();// Need requestID => Request Class

        //Function: View the Reviews list from the occupied House
        void viewOccupiedHouseReview(house::House *house, int score, std::string cmt);

        // Function: View a specific Occupier review
        void viewOccupyReview(int occupierID, int score, std::string cmt);

        std::map<std::string, std::string> to_map() override;
    };

} // account

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_
