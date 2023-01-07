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
    const std::string &House::getCity() const {
        return city;
    }
    account::Member *House::getOwner() const {
        return this->owner;
    }
    short House::getRating() const {
        return rating;
    }
    const std::vector<HouseReview *> &House::getReviews() const {
        return reviews;
    }
    HouseListing *House::getListing() const {
        return listing;
    }
    HouseOccupancy *House::getOccupancy() const {
        return occupancy;
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
        if (this->occupancy != nullptr) {
            return true;
        }
        return false;
    }
    std::map<std::string, std::string> House::to_map() {
        return {};
    }


} // house
