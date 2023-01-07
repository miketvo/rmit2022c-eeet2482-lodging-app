#include "House.h"
#include <iostream>
#include <utility>

namespace house {

    House::House() {
        this->city = "";
        this->owner = nullptr;
        this->rating = 0;
        this->reviews = {};
        this->listing = nullptr;
        this->occupancy = nullptr;
    }

    House::House(std::string city,
                 account::Member *owner,
                 short rating,
                 std::vector<HouseReview*> reviews,
                 HouseListing* listing,
                 HouseOccupancy* occupancy) {
        this->city = std::move(city);
        this->owner = owner;
        this->rating = rating;
        this->reviews = std::move(reviews);
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
