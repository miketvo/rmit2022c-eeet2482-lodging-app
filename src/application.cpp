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

    Application() {
        cout << "EEET2482/COSC2082 ASSIGNMENT" << std::endl;
        cout << "VACATION HOUSE EXCHANGE APPLICATION"
             << "\n\n";
        cout << "Instructors: Mr. Linh Tran & Phong Ngo" << std::endl;
        cout << "Group: Group 9" << std::endl;
        cout << "s3963207, Do Le long An" << std::endl;
        cout << "s3963207, Do Le long An" << std::endl;
        cout << "s3963207, Do Le long An" << std::endl;
        cout << "s3963207, Do Le long An"
             << "\n\n\n";
    }

    void init_database() {}

    void load_database() {}

    void save_database() {}

    void reset_database() {}

    bool login(Account account) {
        if (quit == false) {
            return true;
        } else {
            return false;
        }
    }

    void guest_menu() {
    }

    void member_menu() {
    }

    void admin_menu() {
    }

    bool register_member() {
        if () {
            return true;
        } else {
            return false;
        }
    }

    void unregister_member(Member member) {}

  public:
    void main_loop() {
        cout << "\t\t\t"
             << "--> MAIN MENU <--"
             << "\n\n";
        cout << "\t\t\t"
             << "--> 1. Guest"
             << "\n";
        cout << "\t\t\t"
             << "--> 2. Admin"
             << "\n";
        cout << "\t\t\t"
             << "--> 3. Member"
             << "\n";
        cout << "\t\t\t"
             << "--> 4. Exit"
             << "\n\n\n";
        cout << "Enter your choice (Number only): " << std::endl;
        cin >> login_type;
    }
}