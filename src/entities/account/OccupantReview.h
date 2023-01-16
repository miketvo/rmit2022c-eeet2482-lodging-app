#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_

#include "Member.h"
#include <iostream>

namespace account {
    class Member;
    class OccupantReview : public utils::Review {
      private:
        std::string reviewer_id;
        std::string comment;
        double rating;
        std::string occupier_id;

      public:
        OccupantReview();
        OccupantReview(const std::string &reviewer_id, const std::string &comment, double rating, const std::string &occupier_id);
        void from_map(std::map<std::string, std::string> map);
        std::map<std::string, std::string> to_map();
        const std::string &getReviewerId() const;
        void setReviewerId(const std::string &reviewerId);
        const std::string &getComment() const;
        void setComment(const std::string &comment);
        double getRating() const;
        void setRating(double rating);
        const std::string &getOccupierId() const;
        void setOccupierId(const std::string &occupierId);

        friend class Member;
    };

}// namespace account

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_OCCUPANT_REVIEW_H_