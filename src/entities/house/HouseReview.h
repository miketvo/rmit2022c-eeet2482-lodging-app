#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_REVIEW_H_

#include "../../utils/Review.h"
#include "../account/Member.h"
#include "House.h"
#include <iostream>

namespace house {
    class Member;
    class HouseReview : public utils::Review {
      private:
        std::string reviewer_id;
        std::string comment;
        double rating;
        std::string house_id;

      public:
        HouseReview();
        HouseReview(const std::string &reviewer_id,
                    const std::string &comment,
                    double rating,
                    const std::string &house_id);
        const std::string &get_reviewer_id() const;
        void set_reviewer_id(const std::string &reviewer_id);
        const std::string &getComment() const;
        void setComment(const std::string &comment);
        double getRating() const;
        void setRating(double rating);
        const std::string &getHouseId() const;
        void setHouseId(const std::string &houseId);
        void from_map(std::map<std::string, std::string> map) override;
        std::map<std::string, std::string> to_map() override;
        friend class Member;
    };

}// namespace house

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_REVIEW_H_