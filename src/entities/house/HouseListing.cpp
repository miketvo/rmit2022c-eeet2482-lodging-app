#include "HouseListing.h"

#include <utility>

namespace house {
    HouseListing::HouseListing() {
        this->house = nullptr;
        this->requests = {};
        this->rent_per_day = 0;
        this->min_occupier_rating = -10;
    }
    void HouseListing::setRentPerDay(unsigned long rentPerDay) {
        rent_per_day = rentPerDay;
    }
    void HouseListing::setMinOccupierRating(short minOccupierRating) {
        min_occupier_rating = minOccupierRating;
    }
    House *HouseListing::getHouse() const {
        return house;
    }
    const std::vector<HouseRequest *> &HouseListing::getRequests() const {
        return requests;
    }
    unsigned long HouseListing::getRentPerDay() const {
        return rent_per_day;
    }
    short HouseListing::getMinOccupierRating() const {
        return min_occupier_rating;
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