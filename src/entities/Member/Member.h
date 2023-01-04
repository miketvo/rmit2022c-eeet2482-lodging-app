#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_MEMBER_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_MEMBER_H_

#include "../Account/Account.h"
#include <iostream>
#include <vector>

class House;

namespace account {
    static long long id_count = 0;
    class Member: public Entity::Account {
      private:
        long long memberID;
        std::string firstName;
        std::string lastName;
        std::string phoneNumber;
        int creditPoint;
//      Delcare their own House
        House *ownedHouse;

      public:
        Member(long long int id, const std::string &username, const std::string &password, long long int memberId, const std::string &firstName, const std::string &lastName, const std::string &phoneNumber, int creditPoint, House *ownedHouse);
        //Function: Print out info and house info they own
        void show_Testinfo();

        //Get rating score from member
        double getRateScore;
        void view_info();

    };


}
#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_ENTITIES_MEMBER_H_
