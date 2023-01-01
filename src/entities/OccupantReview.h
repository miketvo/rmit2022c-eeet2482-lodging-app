#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_

#include <iostream>
#include "Member.h"
#include "../utils/Review/Review.h"

namespace account {
  class OccupantReview : public utils::Review{
    protected:
      Member reviewer, reviewee;

    public:
      OccupantReview(std::string id = "", std::string comment = "", int rating = 0) : utils::Review(id, comment, rating){};
  };
} // namespace account


#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_