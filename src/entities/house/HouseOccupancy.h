#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSEOCCUPANCY_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSEOCCUPANCY_H_

#include "../Member.h"
#include "House.h"

namespace house {

    class HouseOccupancy {
      private:
        house::House house;
        Member member;

    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSEOCCUPANCY_H_
