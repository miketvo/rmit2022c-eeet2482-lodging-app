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
        std::string id;
        std::string comment;
        int rating;



      public:
        HouseReview();
        HouseReview(const std::string &id,
                    const std::string &comment,
                    int rating = 0);
        const std::string &getId() const;
        void setId(const std::string &id);
        const std::string &getComment() const;
        void setComment(const std::string &comment);
        int getRating() const;
        void setRating(int rating);
        void from_map(std::map<std::string, std::string> map) override;
        std::map<std::string, std::string> to_map() override;
        friend class Member;
    };

}// namespace house

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_REVIEW_H_