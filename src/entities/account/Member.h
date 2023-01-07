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
    class HouseRequest;
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
        std::vector<house::HouseRequest*> requests;

      public:
        Member();
        Member(
            const std::string &username,
            const std::string &password,
            const std::string &first_name,
            const std::string &last_name,
            const std::string &phone_number,
            unsigned int credits = 500
        );

        //Function: Calculate the total rating score from occupant reviewers then get the average rating score
        //=> Get the Rating Score of Each Owner
        double getReviewRate();

        //Function: View the Member Info
        void viewInfo();

        //Function: Create a House for the Owner
        void ownHouse(house::House *house);

        //Function: Unlist the House from the list when the Owner doesn't want to
        void unlistHouse();

        //Function: Get the available house lists
        void availableHouse();

        //Function: Get the available request from own House
        void listRequest();

        //Function: Accept the request from the Occupier
        bool acceptRequest();// Need requestID => Request Class

        //Function: Reject the request from the Occupier
        bool rejectRequest();// Need requestID => Request Class

        // Add review into occupier review list
        void addToMemberReviewList(OccupantReview *review);

        //Function: View the Reviews list from the occupied House
        void reviewHouse(house::House *house, int score, std::string cmt);

        // Function: View a specific Occupier review
        void viewOccupyReview(int occupierID, int score, std::string cmt);

        //Function: Minus the credit point when doing transaction
        void minus(int cre);

        //Function: Add the credit point when doing transaction
        void add(int cre);

        std::map<std::string, std::string> to_map() override;

    };

} // account

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_
