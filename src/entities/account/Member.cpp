#include "Member.h"
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>

namespace account {

    Member::Member(const std::string &id,
                   const std::string &username,
                   const std::string &password,
                   const std::string &first_name,
                   const std::string &last_name,
                   const std::string &phone_number,
                   unsigned int credits)
                   : Account(id, username, password) {

        this->id = id;
        this->first_name = first_name;
        this->last_name = last_name;
        this->phone_number = phone_number;
        this->credits = credits;
        this->house = nullptr;

        reviewList.clear();
    }

    //Get the Rating Score
    double Member::getReviewRate() {
        // Case: If there is no one rate this member account
        if(reviewList.empty()){
            return 0;
        }

        //Using the loop to find out the score from the reviewList
        double reviews = 0;
        for (auto &review: reviewList){
            reviews += review->rating; // For this, declare Member as friend of Occupant Review for access
        }

        //Then, calculate the average rating score for the member
        double averageRatingScore = (double) reviews / (double) reviewList.size();

        std::stringstream sts;
        sts << std::fixed << std::setprecision(1) << averageRatingScore;
        sts >> averageRatingScore;

        return averageRatingScore;
    }

    //View the member info:
    void Member::viewInfo() {
        std::cout << "\n Username: " << username << "\n";
        std::cout << "First name: " << first_name << "\n";
        std::cout << "Last Name: " << last_name << "\n";
        std::cout << "Phone Number: " << phone_number << "\n";
        std::cout << "Credits: " << credits << "\n";
        std::cout << "Review Rate: " << getReviewRate() << "\n";

        if (house != nullptr){
            std::cout << "Owned House Location: " << "\n";
            // display here will be getHouseDetail() from House e.x: house->getHouseDetail()
        }
        std::cout << "\n";
    }




    // Database Related Function
    std::map<std::string, std::string> Member::to_map() {
        return Account::to_map();
    }
} // account
