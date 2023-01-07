#include "HouseOccupancy.h"

#include <utility>

namespace house {

    HouseOccupancy::HouseOccupancy() {
        this->house = nullptr;
        this->occupant = nullptr;
        this->period = utils::time::Period();
    }

    HouseOccupancy::HouseOccupancy(House *house,
                                   account::Member *occupant,
                                   utils::time::Period period) {

        this->house = house;
        this->occupant = occupant;
        this->period = std::move(period);
    }

} // house