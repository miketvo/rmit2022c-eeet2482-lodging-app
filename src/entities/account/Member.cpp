#include "Member.h"
#include <algorithm>
#include <iomanip>
#include <sstream>

namespace account {

    Member::Member() {
        this->memberID = "";
        this->credits = 500;
        this->first_name = "";
        this->last_name = "";
        this->phone_number = "";
        this->house = nullptr;
        this->rating_score = 10;
    }
    void Member::setCredits(unsigned int credit) {
        this->credits = credit;
    }

    house::House *Member::getHouse() const {
        return this->house;
    }

    Member::Member(
        const std::string &memberID,
        const std::string &username,
        const std::string &password,
        const std::string &first_name,
        const std::string &last_name,
        const std::string &phone_number,
        unsigned int credits,
        double rating_score) : Account(username, password) {
        this->memberID = memberID;
        this->credits = credits;
        this->first_name = first_name;
        this->last_name = last_name;
        this->phone_number = phone_number;
        this->credits = credits;
        this->house = nullptr;
        this->rating_score = rating_score;
    }

    unsigned int Member::get_credits() const {
        return credits;
    }

    const std::string &Member::get_first_name() const {
        return first_name;
    }

    const std::string &Member::get_last_name() const {
        return last_name;
    }

    const std::string &Member::get_phone_number() const {
        return phone_number;
    }

    const std::string &Member::get_id() const {
        return this->memberID;
    }

    double Member::getRatingScore() const {
        return rating_score;
    }

    void Member::setRatingScore(double ratingScore) {
        rating_score = ratingScore;
    }

    void Member::from_map(std::map<std::string, std::string> map) {
        Account::from_map(map);
        this->memberID = map["member_id"];
        this->first_name = map["first_name"];
        this->last_name = map["last_name"];
        this->phone_number = map["phone_number"];
        this->credits = std::stoul(map["credits"]);
        this->rating_score = std::stod(map["rating_score"]);
    }

    std::map<std::string, std::string> Member::to_map() {
        std::map<std::string, std::string> map = Account::to_map();
        map.emplace("member_id", this->memberID);
        map.emplace("first_name", this->first_name);
        map.emplace("last_name", this->last_name);
        map.emplace("phone_number", this->phone_number);
        map.emplace("credits", std::to_string(this->credits));
        map.emplace("rating_score", std::to_string(this->rating_score));
        return map;
    }

}// namespace account
