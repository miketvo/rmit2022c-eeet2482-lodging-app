#include "HouseOccupancy.h"

#include <utility>

namespace house {

    HouseOccupancy::HouseOccupancy() {
        this->house = nullptr;
        this->occupant = nullptr;
    }

    HouseOccupancy::HouseOccupancy(House *house,
                                   account::Member *occupant,
                                   const utils::time::Datetime& start,
                                   const utils::time::Datetime& end
                                   ) {

        this->house = house;
        this->occupant = occupant;
        this->period.set_start(start);
        this->period.set_end(end);
    }
    House *HouseOccupancy::getHouse() const {
        return house;
    }
    account::Member *HouseOccupancy::getOccupant() const {
        return occupant;
    }
    const utils::time::Period &HouseOccupancy::getPeriod() const {
        return period;
    }

} // house