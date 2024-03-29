#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_

#include "../account/Member.h"
#include "HouseOccupancy.h"
#include "HouseReview.h"
#include <iostream>
#include <map>
#include <vector>

namespace house {

    class HouseOccupancy;
    class HouseReview;
    class HouseRequest;

    class House {
      private:
        std::string houseID;
        std::string city;
        std::string houseOwner;
        int credit;
        int minimum_review_score;
        double rating_score;
        account::Member *owner;
        std::vector<HouseReview*> reviews;
        HouseOccupancy *occupancy;
        std::vector<HouseRequest*> requests;
//        utils::time::Period period;
      public:
        House();

        House(std::string &city,
              std::string &houseOwner,
              std::string &houseID,
              int credit,
              int minimum_review_score,
              double rating_score);

        std::map<std::string, std::string> to_map();
        void from_map(std::map<std::string, std::string> map);

        bool is_available();
        const std::string &getCity() const;
        account::Member *getOwner() const;
        const std::string &getHouseOwner() const;
        const std::vector<HouseReview *> &getReviews() const;
        HouseOccupancy *getOccupancy() const;

        friend class account::Member;
        const std::string get_house_id() const;
        const int get_credit() const;
        const int get_minimum_review_score() const;
        const std::vector<HouseRequest *> &getRequests() const;
        void setRequests(house::HouseRequest &requests);
        const double get_rating_score() const;
        void setRatingScore(double ratingScore);

    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_
