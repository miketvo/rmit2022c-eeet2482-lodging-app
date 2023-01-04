#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_APPLICATION_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_APPLICATION_H_

#include "entities/Account.h"
#include "entities/Admin.h"
#include "entities/House/House.h"
#include "entities/Member.h"
#include <string>
#include <vector>

enum LoginType { GUEST, MEMBER, ADMIN };

class Application {
  private:
    bool quit;
    std::string database_path;
    LoginType login_type;
    std::vector<House> houses;
    std::vector<Member> members;
    std::vector<std::string> cities;
    Admin admin;

    void init_database();
    void load_database();
    void save_database();
    void reset_database();
    bool login(Account account);
    void guest_menu();
    void member_menu();
    void admin_menu();
    bool register_member();
    void unregister_member(Member member);
  public:
    Application();
    Application(const std::string &database_path);

    void main_loop();
};

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_APPLICATION_H_
