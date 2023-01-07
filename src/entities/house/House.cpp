#include "House.h"
#include <iostream>

namespace house {

    House::House(std::string city,
                 account::Member *owner,
                 short rating,
                 std::vector<HouseReview> reviews,
                 HouseListing listing,
                 HouseOccupancy occupancy) {
        this->city = city;
        this->owner = owner;
        this->rating = rating;
        this->reviews = reviews;
        this->listing = listing;
        this->occupancy = occupancy;
    }
    bool House::is_available() {
        if (1) {
            return true;
        }
        return false;
    }
    std::map<std::string, std::string> House::to_map() {
        return {};
    }

} // house
