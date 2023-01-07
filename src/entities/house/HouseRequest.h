//
// Created by Dole longAn on 7/1/2023.
//

#ifndef RMIT2022C_EEET2482_LODGING_APP_HOUSEREQUEST_H
#define RMIT2022C_EEET2482_LODGING_APP_HOUSEREQUEST_H

#include "../account/Member.h"
namespace house {
    class HouseRequest {
      private:
        account::Member *requester;
      public:
        HouseRequest();
        explicit HouseRequest(account::Member *requester);
        account::Member *getRequester() const;

        friend class account::Member;
    };

}

#endif//RMIT2022C_EEET2482_LODGING_APP_HOUSEREQUEST_H
