//
// Created by Dole longAn on 7/1/2023.
//

#include "HouseRequest.h"

namespace house {
    HouseRequest::HouseRequest() {
        this->requester = nullptr;
        this->house_requested = nullptr;
    }
    void HouseRequest::setRequester(account::Member *requester) {
        this->requester = requester;
    }
    account::Member *HouseRequest::getRequester() const {
        return this->requester;
    };
    House *HouseRequest::getHouseRequested() const {
        return this->house_requested;
    }
    void HouseRequest::setHouseRequested(House *houseRequested) {
        this->house_requested = houseRequested;
    }
    HouseRequest::HouseRequest(account::Member *requester,
                               House *house_requested){
        this->requester = requester;
        this->house_requested = house_requested;
    }
    void HouseRequest::from_map(std::map<std::string, std::string> map) {
        std::string requesterName;
        requesterName = this->requester->get_username();
        std::string houseRequestID;
        houseRequestID = this->house_requested->get_house_id();
        requesterName = map["requester"];
        houseRequestID = map["houseRequestID"];
    }
    std::map<std::string, std::string> HouseRequest::to_map() {
        std::map<std::string, std::string> map;
        std::string requesterName;
        requesterName = this->requester->get_username();
        std::string houseRequestID;
        houseRequestID = this->house_requested->get_house_id();
        map.emplace("requester", requesterName);
        map.emplace("house_request_ID", houseRequestID);
        return map;
    }
}