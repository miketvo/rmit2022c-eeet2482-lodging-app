#include "HouseReview.h"

void HouseReview::show_house_review() {
    std::cout << "Review" << std::endl;
};

HouseReview::HouseReview() {
    this->id = "";
    this->rating = 0;
    this->comment = "";
};

HouseReview::HouseReview(std::string id, int rating, std::string comment) {
    this->id = id;
    this->rating = rating;
    this->comment = comment;
}