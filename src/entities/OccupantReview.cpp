#include "OccupantReview.h"

void OccupantReview::show_occupant_review() {
    std::cout << "test" << std::endl;
};

OccupantReview::OccupantReview() {
    this->id = "";
    this->rating = 0;
    this->comment = "";
}

OccupantReview::OccupantReview(std::string id, int rating, std::string comment) {
    this->id = id;
    this->rating = rating;
    this->comment = comment;
}