#include "HouseListing.h"

#include <utility>

namespace house {
    HouseListing::HouseListing() {
        this->house = nullptr;
        this->requests = {};
    }
    House *HouseListing::getHouse() const {
        return house;
    }
    const std::vector<HouseRequest *> &HouseListing::getRequests() const {
        return requests;
    }
    void HouseListing::add_request(HouseRequest request) {
        this->requests[this->requests.size()] = &request;
    }
    HouseListing::HouseListing(House *house,
                               std::vector<house::HouseRequest*> requests) {
        this->house = house;
        this->requests = std::move(requests);
    }
} // house