#include "House.h"
#include <iostream>
#include <utility>

namespace house {

    House::House() {
        this->city = "";
        this->houseOwner = "";
        this->houseID = 0;
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

    House::House(std::string &city,
                 std::string &houseOwner,
                 int &houseID) {

        this->city = city;
        this->houseOwner = houseOwner;
        this->houseID = houseID;
//        this->period.set_start(start);
//        this->period.set_end(end);
    }
    bool House::is_available() {
        if (this->occupancy != nullptr) {
            return true;
        }
        return false;
    }
    void House::from_map(std::map<std::string, std::string> map) {
        std::to_string(houseID) = map["houseID"];
        this->city = map["city"];
        this->houseOwner = map["houseOwner"];
    }
    std::map<std::string, std::string> House::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("houseID", std::to_string(houseID));
        map.emplace("city", this->city);
        map.emplace("houseOwner", this->houseOwner);
//        map.emplace("owner", this->owner->get_username());
        return map;
    }


} // house
