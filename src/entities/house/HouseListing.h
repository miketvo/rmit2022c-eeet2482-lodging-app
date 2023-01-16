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
      public:
        HouseListing();
        HouseListing(House *house,
                       std::vector<house::HouseRequest*> requests);
        House *getHouse() const;
        const std::vector<HouseRequest *> &getRequests() const;
        void add_request(HouseRequest request);
    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_LISTING_H_
