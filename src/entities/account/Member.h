#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_

#include "../../utils/Review.h"
#include "../../utils/time/Period.h"
#include "../house/House.h"
#include "Account.h"
#include "OccupantReview.h"
#include <iostream>
#include <vector>

namespace utils {
    namespace time {
        class Period;
    }
}

namespace house {
    class House;
    class HouseRequest;
}

namespace account {
    class OccupantReview;

    class Member : public Account {
      private:
        unsigned credits;
        double rating_score;
        std::string memberID;
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        house::House *house;
        std::vector<OccupantReview *> reviews;
        std::vector<house::HouseRequest*> requests;

      public:
        Member();
        Member(
            const std::string &memberID,
            const std::string &username,
            const std::string &password,
            const std::string &first_name,
            const std::string &last_name,
            const std::string &phone_number,
            unsigned int credits = 500,
            double rating_score = 10
        );

        unsigned int get_credits() const;
        const std::string &get_first_name() const;
        const std::string &get_last_name() const;
        const std::string &get_phone_number() const;
        const std::string &get_id() const;
        house::House *getHouse() const;
        double get_rating();

        void from_map(std::map<std::string, std::string> map) override;
        std::map<std::string, std::string> to_map() override;
    };

} // account

#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_ACCOUNT_MEMBER_H_
