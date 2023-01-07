#include "HouseReview.h"

namespace house {

    HouseReview::HouseReview(const std::string &id, const std::string &comment, short rating) {
    }

    std::map<std::string, std::string> HouseReview::to_map() {
        return Review::to_map();
    }
}// namespace house