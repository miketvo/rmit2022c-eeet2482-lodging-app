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

    class House {
      private:
        std::string city;
        account::Member *owner;
        short int rating;
        std::vector<HouseReview> reviews;
        HouseListing listing;
        HouseOccupancy occupancy;
      public:
        House() = default;

        House(std::string city,
              account::Member *owner,
              short int rating,
              std::vector<HouseReview> reviews,
              HouseListing listing,
              HouseOccupancy occupancy);

        std::map<std::string, std::string> to_map();

        bool is_available();


    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_
