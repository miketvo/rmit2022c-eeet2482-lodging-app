#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_OCCUPANCY_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_OCCUPANCY_H_

#include "House.h"
#include "HouseRequest.h"
#include "../account/Member.h"
#include "../../utils/time/Period.h"
#include <vector>

namespace house {

    class House;

    class HouseOccupancy {
      private:
        House* house;
        account::Member *occupant;
        utils::time::Period period;
      public:
        HouseOccupancy() = default;
        HouseOccupancy(House* house,
                       account::Member *occupant,
                       utils::time::Period period);
    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_OCCUPANCY_H_
