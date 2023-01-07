#include "HouseOccupancy.h"

#include <utility>

namespace house {

    HouseOccupancy::HouseOccupancy(House *house,
                                   account::Member *occupant,
                                   utils::time::Period period) {
        this->house = house;
        this->occupant = occupant;
        this->period = std::move(period);
    }
} // house