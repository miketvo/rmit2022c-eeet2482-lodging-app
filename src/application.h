#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

class Application {
  private:
    bool quit = false;
    string database_path;
    LoginType login_type;
    vector<House> houses;
    vector<Members> members;
    vector<string> cities;
    Admin admin;

    Application();

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
    void main_loop();
}