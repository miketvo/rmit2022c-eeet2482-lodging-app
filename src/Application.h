#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_APPLICATION_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_APPLICATION_H_

#include <string>
#include <vector>
#include "entities/house/House.h"
#include "entities/account/Admin.h"

enum LoginType { NONE, GUEST, MEMBER, ADMIN };

class Application {
  private:
    bool quit;
    LoginType login_type;
    std::string database_path;
    std::vector<house::HouseReview> house_reviews;
    std::vector<house::HouseRequest> requests;
    std::vector<account::OccupantReview> occupant_reviews;
    std::vector<std::string> cities;
    std::vector<house::House> houses;
    std::vector<account::Member> members;
    account::Admin admin;

    bool detected_database();
    void init_database();
    void load_database();
    void save_database();
    void reset_database();

    bool login(const account::Account &account);
    void guest_menu();
    void guest_view_house();
    void member_menu();
    void admin_menu();

    bool register_member();
    void add_house(account::Member &current_member);
    void house_details(std::string buffer, std::string id);
    void rate_occupied_house(account::Member &current_member);
    std::vector<house::House> list_house_available(account::Member &current_member);
    void check_house_request_list(account::Member &current_member);
    bool request_house_to_occupy(account::Member &current_member, std::vector<house::House> temp_vector);
    void remove_request(std::vector<house::HouseRequest> request_list, std::string house_requestedID, std::string requester_ID);
    void update_credit(std::string requester_ID, std::string house_requestedID);
    void rate_occupier(account::Member &current_member);

    static int prompt_choice(unsigned min, unsigned max);
  public:
    Application();

    void main_loop();
};

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_APPLICATION_H_
