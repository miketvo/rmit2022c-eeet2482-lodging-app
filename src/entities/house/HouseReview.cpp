#include "HouseReview.h"

namespace house {

    HouseReview::HouseReview() {
        this->reviewer_id = "";
        this->comment = "";
        this->rating = 0;
        this->house_id = "";
    }

    const std::string &HouseReview::get_reviewer_id() const {
        return reviewer_id;
    }
    void HouseReview::set_reviewer_id(const std::string &reviewer_id) {
        HouseReview::id = id;
    }
    const std::string &HouseReview::getComment() const {
        return comment;
    }
    void HouseReview::setComment(const std::string &comment) {
        HouseReview::comment = comment;
    }
    double HouseReview::getRating() const {
        return rating;
    }
    void HouseReview::setRating(double rating) {
        HouseReview::rating = rating;
    }
    const std::string &HouseReview::getHouseId() const {
        return house_id;
    }
    void HouseReview::setHouseId(const std::string &houseId) {
        house_id = houseId;
    }

    HouseReview::HouseReview(const std::string &reviewer_id, const std::string &comment, double rating, const std::string &house_id) {
        this->reviewer_id = reviewer_id;
        this->comment = comment;
        this->rating = rating;
        this->house_id = house_id;
    }
    void HouseReview::from_map(std::map<std::string, std::string> map) {
        this->reviewer_id = map["Reviewer's ID"];
        this->comment = map["Comment"];
        this->rating = std::stod(map["Rating_score"]);
        this->house_id = map["House's ID"];
    }

    std::map<std::string, std::string> HouseReview::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("Reviewer's ID", this->reviewer_id);
        map.emplace("Comment", this->comment);
        map.emplace("Rating_score", std::to_string(this->rating));
        map.emplace("House's ID", this->house_id);
        return map;
    }
}// namespace house