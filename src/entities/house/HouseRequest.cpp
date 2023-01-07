//
// Created by Dole longAn on 7/1/2023.
//

#include "HouseRequest.h"

namespace house {
    HouseRequest::HouseRequest() {
        this->requester = nullptr;
    }
    HouseRequest::HouseRequest(account::Member *requester){
        this->requester = requester;
    }
    account::Member *HouseRequest::getRequester() const {
        return requester;
    };
}