#include "HouseListing.h"

namespace house {
    HouseListing::HouseListing(House *house,
                               std::vector<house::HouseRequest*> requests,
                               unsigned long rent_per_day,
                               short min_occupier_rating) {
        this->house = house;
        this->requests = requests;
        this->rent_per_day = rent_per_day;
        this->min_occupier_rating = min_occupier_rating;
    }
} // house