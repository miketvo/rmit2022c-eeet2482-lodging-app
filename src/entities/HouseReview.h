#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSEREVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSEREVIEW_H_

#include "House.h"
#include "Member.h"
#include <iostream>

namespace HouseReview {
  class HouseReview {
    private:
      std::string id;
      std::string comment;
      int rating;
      Member member;
      House house;

    public:
      HouseReview();
      HouseReview(std::string id, int rating, std::string comment);
      void show_house_review();
};
}


#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSEREVIEW_H_