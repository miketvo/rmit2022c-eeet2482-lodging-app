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
        std::string requester_username;
        std::string request_status;

      public:
        HouseRequest();
        HouseRequest(const std::string &requester_id,
                              const std::string &house_requested_id,
                              const std::string &requester_username,
                              const std::string &request_status);

        void from_map(std::map<std::string, std::string> map);
        std::map<std::string, std::string> to_map();

        void setRequester(account::Member *requesterID);
        void setHouseRequested(House *houseRequestedID);
        House *getHouseRequested() const;
        void setRequesterId(const std::string &requesterId);
        void setHouseRequestedId(const std::string &houseRequestedId);
        void setRequesterName(const std::string &requester_username);
        const std::string &getRequesterId() const;
        const std::string &getHouseRequestedId() const;
        const std::string &getRequesterUsername() const;
        const std::string &getRequestStatus() const;
        void setRequestStatus(const std::string &requestStatus);

        friend class account::Member;
    };

}// namespace house

#endif//RMIT2022C_EEET2482_LODGING_APP_HOUSEREQUEST_H
