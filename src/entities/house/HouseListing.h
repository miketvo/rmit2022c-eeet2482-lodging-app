#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_LISTING_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_LISTING_H_

#include <map>
#include <string>
#include "HouseRequest.h"
#include <vector>

namespace house {

    class House;
    class HouseRequest;

    class HouseListing {
      private:
        House *house;
        std::vector<HouseRequest *> requests;
        unsigned long rent_per_day;
        short int min_occupier_rating;
      public:
        HouseListing();
        HouseListing(House *house,
                       std::vector<house::HouseRequest*> requests,
                       unsigned long rent_per_day,
                       short int min_occupier_rating = -10);
        House *getHouse() const;
        const std::vector<HouseRequest *> &getRequests() const;
        unsigned long getRentPerDay() const;
        std::string getMinOccupierRating();
        void setRentPerDay(unsigned long rentPerDay);
        void setMinOccupierRating(short minOccupierRating);
        std::map<std::string, std::string> to_map();
    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_LISTING_H_
