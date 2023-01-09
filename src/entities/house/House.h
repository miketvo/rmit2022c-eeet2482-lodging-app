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
        std::vector<HouseReview*> reviews;
        HouseListing* listing;
        HouseOccupancy *occupancy;
        utils::time::Period period;
      public:
        House();

        House(std::string &city,
              account::Member *owner,
              const utils::time::Datetime& start,
              const utils::time::Datetime& end);

        std::map<std::string, std::string> to_map();
        void from_map(std::map<std::string, std::string> map);

        bool is_available();
        const std::string &getCity() const;
        account::Member *getOwner() const;
        short getRating() const;
        const std::vector<HouseReview *> &getReviews() const;
        HouseListing *getListing() const;
        HouseOccupancy *getOccupancy() const;

        friend class account::Member;
        void setCity(std::string city);
    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_
