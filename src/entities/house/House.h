#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_H_

#include <iostream>
#include "../Member.h"
#include <vector>

namespace house {

    class House {
      private:
        std::string city;
        Member owner;
        short int rating;

    };

} // house


#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_H_
