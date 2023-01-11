#include "House.h"
#include <iostream>
#include <utility>

namespace house {

    House::House() {
        this->city = "";
        this->houseOwner = "";
        this->houseID = "";
        this->credit = 0;
        this->minimum_review_score = 0;
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

    const std::string House::get_house_id() const {
        return houseID;
    };

    const int House::get_credit() const {
        return this->credit;
    }

    const int House::get_minimum_review_score() const {
        return this->minimum_review_score;
    }

    House::House(std::string &city,
                 std::string &houseOwner,
                 std::string &houseID, int credit, int minimum_review_score) {

        this->city = city;
        this->houseOwner = houseOwner;
        this->houseID = houseID;
        this->credit = credit;
        this->minimum_review_score = minimum_review_score;
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
        this->credit = std::stoul(map["credit"]);
        this->minimum_review_score = std::stoul(map["minimum_review_score"]);
    }
    std::map<std::string, std::string> House::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("houseID", this->houseID);
        map.emplace("city", this->city);
        map.emplace("houseOwner", this->houseOwner);
        map.emplace("credit", std::to_string(this->credit));
        map.emplace("minimum_review_score", std::to_string(this->minimum_review_score));
        //        map.emplace("owner", this->owner->get_username());
        return map;
    }

}// namespace house
