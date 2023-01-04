#ifndef RMIT2022C_EEET2482_LODGING_APP_HOUSEREVIEW_H
#define RMIT2022C_EEET2482_LODGING_APP_HOUSEREVIEW_H

#include <iostream>
#include "./House.h"

    namespace House {
    class HouseReview {
      private:
        std::string id;
        Member owner;
        short int rating;
        std::string comment;
    };
    void show_house_review();
}

#endif//RMIT2022C_EEET2482_LODGING_APP_HOUSEREVIEW_H
