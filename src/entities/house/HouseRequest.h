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
      public:
        HouseRequest();
        explicit HouseRequest(account::Member *requester,
                              House *house_requested);
        void from_map(std::map<std::string, std::string> map);
        std::map<std::string, std::string> to_map();

        void setRequester(account::Member *requester);
        account::Member *getRequester() const;

        void setHouseRequested(House *houseRequested);
        House *getHouseRequested() const;

        friend class account::Member;
    };

}

#endif//RMIT2022C_EEET2482_LODGING_APP_HOUSEREQUEST_H
