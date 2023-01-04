#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_H_

#include <iostream>
#include "../Member.h"
#include "./HouseReview.h"
#include <vector>

namespace house {
    class House {
      private:
        std::string city;
        Member owner;
        short int rating;
        std::vector<HouseReview> reviews;


    };
}


#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_H_
