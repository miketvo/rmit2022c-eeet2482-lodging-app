#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSEREVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSEREVIEW_H_

#include "../House.h"
#include "Member.h"
#include <iostream>
#include "../../utils/Review/Review.h"
namespace house {
    class HouseReview : public utils::Review {
        protected:
            House house;
            Member reviewer;

            public:
            HouseReview(std::string id, std::string comment, int rating) : utils::Review(id, comment, rating){};
            void show_house_review();
    };
} // namespace house

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSEREVIEW_H_