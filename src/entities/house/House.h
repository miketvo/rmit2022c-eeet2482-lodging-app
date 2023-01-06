#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_

#include <iostream>
#include <vector>
#include "../account/Member.h"
#include <map>

namespace account {
    class Member;
}

namespace house {

    class House {
      private:
        std::string city;
        account::Member *owner;
        short rating;

      private:
        House() = default;

        std::map<std::string, std::string> to_map();
    };

} // house

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_HOUSE_HOUSE_H_
