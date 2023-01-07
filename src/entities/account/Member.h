#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_

#include <iostream>
#include <vector>
#include "../../utils/Review.h"
#include "../house/House.h"
#include "Account.h"
#include "OccupantReview.h"


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
        Member(const std::string &id,
               const std::string &username,
               const std::string &password,
               const std::string &first_name,
               const std::string &last_name,
               const std::string &phone_number,
               unsigned int credits);

        std::map<std::string, std::string> to_map() override;

        //Function: View the Member Info
        void viewInfo();

        //Function: Calculate the total rating score from occupant reviewers then get the average rating score
        //=> Get the Rating Score of Each Owner
        double getReviewRate();

        //        Function: List House Info from the Owner
        void listHouseDetails();

        //Function: Unlist the House from the list when the Owner doesn't want to
        bool unlistHouse();

        //Function: Get the available house lists
        void availableHouse();

        //Function: Get the available request from own House
        void listRequest();

        //Function: Accept the request from the Occupier
        bool acceptRequest(); // Need requestID => Request Class

        //Function: Reject the request from the Occupier
        bool rejectRequest(); // Need requestID => Request Class

        //Function: View the Reviews list from the occupied House
        void viewOccupiedHouseReview(house::House *house, int score, std::string cmt);

        // Function: View a specific Occupier review
        void viewOccupyReview(int occupierID, int score, std::string cmt);
    };

}// namespace account

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_
