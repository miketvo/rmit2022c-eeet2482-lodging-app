//
// Created by Dole longAn on 7/1/2023.
//

#include "HouseRequest.h"

namespace house {
    HouseRequest::HouseRequest() {
        this->requester_id = "";
        this->house_requested_id = "";
        this->requester = nullptr;
        this->house_requested = nullptr;
    }
    void HouseRequest::setRequesterId(const std::string &requesterId) {
        requester_id = requesterId;
    }
    void HouseRequest::setHouseRequestedId(const std::string &houseRequestedId) {
        house_requested_id = houseRequestedId;
    }
    void HouseRequest::setRequester(account::Member *requesterID) {
        this->requester = requesterID;
    }
    account::Member *HouseRequest::getRequester() const {
        return this->requester;
    };
    House *HouseRequest::getHouseRequested() const {
        return this->house_requested;
    }
    void HouseRequest::setHouseRequested(House *houseRequestedID) {
        this->house_requested = houseRequestedID;
    }
    HouseRequest::HouseRequest(std::string &requester_id,
                               std::string &house_requested_id){
        this->requester_id = requester_id;
        this->house_requested_id = house_requested_id;
    }
    void HouseRequest::from_map(std::map<std::string, std::string> map) {
        this->requester_id = map["requester_ID"];
        this->house_requested_id = map["house_request_ID"];
    }
    std::map<std::string, std::string> HouseRequest::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("requester_ID", this->requester_id);
        map.emplace("house_request_ID", this->house_requested_id);
        return map;
    }
}