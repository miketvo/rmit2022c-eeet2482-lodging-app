//
// Created by Dole longAn on 7/1/2023.
//

#include "HouseRequest.h"

namespace house {
    HouseRequest::HouseRequest() {
        this->requester_id = "";
        this->house_requested_id = "";
        this->requester_username = "";
        this->request_status = "pending";
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
    House *HouseRequest::getHouseRequested() const {
        return this->house_requested;
    }
    void HouseRequest::setHouseRequested(House *houseRequestedID) {
        this->house_requested = houseRequestedID;
    }
    void HouseRequest::setRequesterName(const std::string &requester_username) {
        this->requester_username = requester_username;
    }
    const std::string &HouseRequest::getRequesterId() const {
        return requester_id;
    }
    const std::string &HouseRequest::getHouseRequestedId() const {
        return house_requested_id;
    }
    const std::string &HouseRequest::getRequesterUsername() const {
        return requester_username;
    }
    HouseRequest::HouseRequest(const std::string &requester_id,
                               const std::string &house_requested_id,
                               const std::string &requester_username,
                               const std::string &request_status
                               ) {
        this->requester_id = requester_id;
        this->house_requested_id = house_requested_id;
        this->requester_username = requester_username;
        this->request_status =request_status;
    }
    void HouseRequest::from_map(std::map<std::string, std::string> map) {
        this->requester_id = map["requester_ID"];
        this->house_requested_id = map["house_request_ID"];
        this->requester_username = map["requester_username"];
        this->request_status = map["request_status"];
    }
    std::map<std::string, std::string> HouseRequest::to_map() {
        std::map<std::string, std::string> map;
        map.emplace("requester_ID", this->requester_id);
        map.emplace("house_request_ID", this->house_requested_id);
        map.emplace("requester_username", this->requester_username);
        map.emplace("request_status", this->request_status);
        return map;
    }
    const std::string &HouseRequest::getRequestStatus() const {
        return request_status;
    }
    void HouseRequest::setRequestStatus(const std::string &requestStatus) {
        request_status = requestStatus;
    }

}// namespace house