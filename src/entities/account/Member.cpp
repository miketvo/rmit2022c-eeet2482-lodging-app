#include "Member.h"
#include <algorithm>
#include <iomanip>
#include <sstream>

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

    //Get the Rating Score
    double Member::getReviewRate() {
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
        double averageRatingScore = (double) rv / (double) reviews.size();

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

        if (house != nullptr) {
            std::cout << "Owned House Location: "
                      << "\n";
            // display here will be getHouseDetail() from House e.x: house->getHouseDetail()
        }
        std::cout << "\n";
    }

    // Create a House for the Owner
    void Member::ownHouse(house::House *newHouse) {
        if (newHouse == nullptr) {
            std::cout << "No house"
                      << "\n";
        } else {
            house = newHouse;
            newHouse->owner = this;
        }
    }

    //Function: Get the available request from own House
    void Member::listRequest(){
        if (requests.empty()) {
            std::cout << "\n You don't not have any request" << "\n";
        }

        std::cout << "Requests:" << "\n";
        for (int i = 0; i < requests.size(); i++) {
            auto request = requests[i];
            std::cout<< "Member: " << request->requester->first_name << "\n";
        }
    }

    //Add a Review into Review List
    void Member::addToMemberReviewList(OccupantReview *review){
       reviews.push_back(review);
    }

    // View the Reviews list from the occupied House
    void Member::reviewHouse(house::House *house, int score, std::string cmt) {
       auto *review = new OccupantReview(this->username, std::move(cmt), score );
       addToMemberReviewList(review);
    }

    //Minus the credit point when transaction
    void Member::minus(int cre){
        if(cre > credits){
            std::cout << "Your credits is not enough" << "\n";
        }
        credits -= cre;
    }

    //Add the credit point when transaction
    void Member::add(int cre){
        credits += cre;
    }

    // Database Related Function
    std::map<std::string, std::string> Member::to_map() {
        return Account::to_map();
    }
}// namespace account
