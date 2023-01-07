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
    void member_menu();
    void admin_menu();
    bool register_member();

    static int prompt_choice(unsigned min, unsigned max);
  public:
    Application();

    void main_loop();
};

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_APPLICATION_H_
