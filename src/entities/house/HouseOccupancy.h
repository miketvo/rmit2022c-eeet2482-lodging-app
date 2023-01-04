#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_OCCUPANCY_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_OCCUPANCY_H_

#include "House.h"
#include "../account/Member.h"

namespace house {

    class HouseOccupancy {
      private:
        house::House house;
        account::Member member;

      public:
        HouseOccupancy();
    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_OCCUPANCY_H_
