#include "House.h"
#include <iostream>
#include <utility>

namespace house {

    House::House() {
        this->city = "";
        this->houseOwner = "";
        this->houseID = "";
    }

    const std::string &House::getCity() const {
        return city;
    }
    account::Member *House::getOwner() const {
        return this->owner;
    }
    const std::string &House::getHouseOwner() const {
        return this->houseOwner;
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

    const std::string House::get_house_id() const{
        return houseID;
    };

    House::House(std::string &city,
                 std::string &houseOwner,
                 std::string &houseID) {

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
        this->houseID = map["houseID"];
        this->city = map["city"];
        this->houseOwner = map["houseOwner"];
    }
    std::map<std::string, std::string> House::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("houseID", this->houseID);
        map.emplace("city", this->city);
        map.emplace("houseOwner", this->houseOwner);
//        map.emplace("owner", this->owner->get_username());
        return map;
    }

} // house
