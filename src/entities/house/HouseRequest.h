//
// Created by Dole longAn on 7/1/2023.
//

#ifndef RMIT2022C_EEET2482_LODGING_APP_HOUSEREQUEST_H
#define RMIT2022C_EEET2482_LODGING_APP_HOUSEREQUEST_H

#include "../account/Member.h"
namespace house {
    class House;
    class HouseRequest {
      private:
        account::Member *requester;
        House *house_requested;
        std::string requester_id;
        std::string house_requested_id;
      public:
        HouseRequest();
        explicit HouseRequest(std::string &requester_id,
                              std::string &house_requested_id);

        void from_map(std::map<std::string, std::string> map);
        std::map<std::string, std::string> to_map();

        void setRequester(account::Member *requesterID);
        account::Member *getRequester() const;

        void setHouseRequested(House *houseRequestedID);
        House *getHouseRequested() const;

        void setRequesterId(const std::string &requesterId);
        void setHouseRequestedId(const std::string &houseRequestedId);

        friend class account::Member;
    };

}

#endif//RMIT2022C_EEET2482_LODGING_APP_HOUSEREQUEST_H
