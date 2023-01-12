#include "HouseReview.h"

namespace house {

    HouseReview::HouseReview() {
        this->id = "";
        this->comment = "";
        this->rating = 0;
    }

    void HouseReview::from_map(std::map<std::string, std::string> map) {
        this->id = map["Reviewer's ID"];
        this->comment = map["Comment"];
        this->rating = std::stod(map["Rating_score"]);
    }

    std::map<std::string, std::string> HouseReview::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("Reviewer's ID", this->id);
        map.emplace("Comment", this->comment);
        map.emplace("Rating_score", std::to_string(this->rating));
        return map;
    }
    const std::string &HouseReview::getId() const {
        return id;
    }
    void HouseReview::setId(const std::string &id) {
        HouseReview::id = id;
    }
    const std::string &HouseReview::getComment() const {
        return comment;
    }
    void HouseReview::setComment(const std::string &comment) {
        HouseReview::comment = comment;
    }
    int HouseReview::getRating() const {
        return rating;
    }
    void HouseReview::setRating(int rating) {
        HouseReview::rating = rating;
    }
    HouseReview::HouseReview(const std::string &id, const std::string &comment, int rating) {
        this->id = id;
        this->comment = comment;
        this->rating = rating;
    }
}// namespace house