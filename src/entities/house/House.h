#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_

#include "../account/Member.h"
#include "HouseListing.h"
#include "HouseOccupancy.h"
#include "HouseReview.h"
#include <iostream>
#include <map>
#include <vector>

namespace house {

    class HouseOccupancy;
    class HouseListing;
    class HouseReview;

    class House {
      private:
        std::string city;
        account::Member *owner;
        short int rating;
        std::vector<HouseReview *> reviews;
        HouseListing *listing;
        HouseOccupancy *occupancy;

      public:
        House();

        House(std::string city,
              account::Member *owner,
              short int rating,
              std::vector<HouseReview *> reviews,
              HouseListing *listing,
              HouseOccupancy *occupancy);

        std::map<std::string, std::string> to_map();

        bool is_available();
        void setCity(std::string city);
        void setOwner(std::string *owner);
        const std::string &getCity() const;
        account::Member *getOwner() const;
        short getRating() const;
        const std::vector<HouseReview *> &getReviews() const;
        HouseListing *getListing() const;
        HouseOccupancy *getOccupancy() const;

        friend class account::Member;
    };

}// namespace house

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_
