#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_REVIEW_H_

#include <iostream>
#include "../../utils/Review.h"
#include "House.h"

namespace house {

    class HouseReview : public utils::Review {
      protected:
        house::House house;
        account::Member reviewer;

      public:
        HouseReview(const std::string &id, const std::string &comment, short rating) : utils::Review(id, comment, rating);

        std::map<std::string, std::string> to_map() override;
    };

} // namespace house

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_REVIEW_H_