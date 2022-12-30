#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_

#include <iostream>
#include "Member.h"

namespace OccupantReview {
  class OccupantReview {
    private:
      std::string id;
      int rating;
      std::string comment;
      Member member;

    public:
      OccupantReview();
      OccupantReview(std::string id, int rating, std::string comment);
      void show_occupant_review();
};
}


#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_
