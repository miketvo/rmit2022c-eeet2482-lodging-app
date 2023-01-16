#include "OccupantReview.h"

namespace account {

    OccupantReview::OccupantReview() {
        this->reviewer_id = "";
        this->comment = "";
        this->rating = 0;
        this->occupier_id = "";
    }

    OccupantReview::OccupantReview(const std::string &reviewer_id, const std::string &comment, double rating, const std::string &occupier_id) {
        this->reviewer_id = reviewer_id;
        this->comment = comment;
        this->rating = rating;
        this->occupier_id = occupier_id;
    }

    void OccupantReview::from_map(std::map<std::string, std::string> map) {
        this->reviewer_id = map["Reviewer's ID"];
        this->comment = map["Comment"];
        this->rating = std::stod(map["Rating_score"]);
        this->occupier_id = map["Occupier's ID"];
    }

    std::map<std::string, std::string> OccupantReview::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("Reviewer's ID", this->reviewer_id);
        map.emplace("Comment", this->comment);
        map.emplace("Rating_score", std::to_string(this->rating));
        map.emplace("Occupier's ID", this->occupier_id);
        return map;
    }
    
    const std::string &OccupantReview::getReviewerId() const {
        return reviewer_id;
    }
    void OccupantReview::setReviewerId(const std::string &reviewerId) {
        reviewer_id = reviewerId;
    }
    const std::string &OccupantReview::getComment() const {
        return comment;
    }
    void OccupantReview::setComment(const std::string &comment) {
        OccupantReview::comment = comment;
    }
    double OccupantReview::getRating() const {
        return rating;
    }
    void OccupantReview::setRating(double rating) {
        OccupantReview::rating = rating;
    }
    const std::string &OccupantReview::getOccupierId() const {
        return occupier_id;
    }
    void OccupantReview::setOccupierId(const std::string &occupierId) {
        occupier_id = occupierId;
    }


}// namespace account
