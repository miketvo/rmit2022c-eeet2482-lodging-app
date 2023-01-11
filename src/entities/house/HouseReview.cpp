#include "HouseReview.h"

namespace house {

    HouseReview::HouseReview(const std::string &id, const std::string &comment, int rating) {
    }

    void HouseReview::from_map(std::map<std::string, std::string> map) {

    }

    std::map<std::string, std::string> HouseReview::to_map() {
        std::map<std::string, std::string> map = Review::to_map();
        map.emplace("Review's ID", this->id);
        map.emplace("Comment", this->comment);
        map.emplace("Rating_score", std::to_string(this->rating));
        return map;
    }
}// namespace house