#include <algorithm>
#include <iomanip>
#include <sstream>
#include "Member.h"

namespace account {

    Member::Member() {
        this->credits = 500;
        this->first_name = "";
        this->last_name = "";
        this->phone_number = "";
        this->house = nullptr;
    }

    Member::Member(
        const std::string &username,
        const std::string &password,
        const std::string &first_name,
        const std::string &last_name,
        const std::string &phone_number,
        unsigned int credits
    ) : Account(username, password) {
        this->credits = credits;
        this->first_name = first_name;
        this->last_name = last_name;
        this->phone_number = phone_number;
        this->credits = credits;
        this->house = nullptr;
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


    //Get the Rating Score
    double Member::get_rating() {
        // Case: If there is no one rate this member account
        if (reviews.empty()) {
            return 0;
        }

        //Using the loop to find out the score from the reviewList
        double rv = 0;
        for (auto &review : reviews) {
            rv += review->rating;// For this, declare Member as friend of Occupant Review for access
        }

        //Then, calculate the average rating score for the member
        double rating = (double) rv / (double) reviews.size();

        std::stringstream sts;
        sts << std::fixed << std::setprecision(1) << rating;
        sts >> rating;

        return rating;
    }


    void Member::from_map(std::map<std::string, std::string> map) {
        Account::from_map(map);
        this->first_name = map["first_name"];
        this->last_name = map["last_name"];
        this->phone_number = map["phone_number"];
        this->credits = std::stoul(map["credits"]);
    }

    std::map<std::string, std::string> Member::to_map() {
        return Account::to_map();
    }
}// namespace account
