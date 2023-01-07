#include "OccupantReview.h"

namespace account {

    OccupantReview::OccupantReview(const std::string &id, const std::string &comment, short rating) {
    }

    std::map<std::string, std::string> OccupantReview::to_map() {
        return Review::to_map();
    }

}// namespace account
