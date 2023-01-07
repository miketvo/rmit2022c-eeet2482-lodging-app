#include "HouseListing.h"

#include <utility>

namespace house {
    HouseListing::HouseListing() {
        this->house = nullptr;
        this->rent_per_day = 0;
        this->min_occupier_rating = -10;
    }

    HouseListing::HouseListing(House *house,
                               std::vector<house::HouseRequest*> requests,
                               unsigned long rent_per_day,
                               short min_occupier_rating) {
        this->house = house;
        this->requests = std::move(requests);
        this->rent_per_day = rent_per_day;
        this->min_occupier_rating = min_occupier_rating;
    }
} // house