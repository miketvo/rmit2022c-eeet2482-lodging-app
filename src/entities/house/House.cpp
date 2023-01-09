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

    void House::setCity(std::string city){
        this->city = city;
    };

    House::House(std::string city,
                 account::Member *owner,
                 short rating,
                 std::vector<HouseReview*> reviews,
                 HouseListing* listing,
                 HouseOccupancy* occupancy,
                 const utils::time::Datetime& start,
                 const utils::time::Datetime& end) {

        this->city = std::move(city);
        this->owner = owner;
        this->rating = rating;
        this->reviews = std::move(reviews);
        this->listing = listing;
        this->occupancy = occupancy;
        this->period.set_start(start);
        this->period.set_end(end);
    }

    bool House::is_available() {
        if (this->occupancy != nullptr) {
            return true;
        }
        return false;
    }
    void House::from_map(std::map<std::string, std::string> map) {
        this->city = map["city"];
        this->owner->get_username() = map["owner"];
        std::to_string(this->rating) = map["rating"];
    }
    std::map<std::string, std::string> House::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("city", this->city);
        map.emplace("owner", this->owner->get_username());
        map.emplace("rating", std::to_string(this->rating));
        return {};
    }


} // house
