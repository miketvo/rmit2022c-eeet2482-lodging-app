#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_LISTING_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_LISTING_H_

#include "HouseRequest.h"
#include <map>
#include <string>

namespace house {

    class HouseListing {
      private:
        house::House *house{};
        std::vector<HouseRequest*> requests;
        unsigned long rent_per_day{};
        short int min_occupier_rating{};
      public:
        HouseListing() = default;
        HouseListing(House *house,
                       std::vector<house::HouseRequest*> requests,
                       unsigned long rent_per_day,
                       short int min_occupier_rating = -10);
    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_LISTING_H_
