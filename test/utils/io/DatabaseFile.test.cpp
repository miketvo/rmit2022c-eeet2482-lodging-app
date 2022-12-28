#include <iostream>
#include <vector>
#include <map>
#include "../../../src/utils/io/DatabaseFile.h"

int main(int argc, char *argv[]) {
    try {
        if (argc == 1) {
            utils::DatabaseFile test_db;

            if (test_db.get_delim() != ",") return 1;
            if (test_db.size() != 0) return 1;
            if (!test_db.empty()) return 1;
            if (test_db.open()) return 1;
            if (test_db.open("ThisDoesNotExist.file")) return 1;

            test_db.set_delim("***");
            if (test_db.get_delim() != "***") return 1;
            test_db.set_delim(",");
            if (test_db.get_delim() != ",") return 1;

            return 0;
        }

        std::vector<std::map<std::string, std::string>> data;

        if (argc == 2) {
            utils::DatabaseFile test_read_db(argv[1]);
            utils::DatabaseFile test_write_db("test/data/new2.dtb");

            if (test_read_db.empty()) return 1;
            test_read_db.unload(data);
            test_write_db.load(data);
            if (test_write_db.empty()) return 1;
            if (test_write_db.size() != test_read_db.size()) return 1;
            if (test_write_db.keys() != test_read_db.keys()) return 1;
            if (!test_write_db.write()) return 1;
            if (!test_write_db.write(data)) return 1;
            if (!test_write_db.write("test/data/new2.dtb", data)) return 1;

            for (size_t i = 0; i < test_read_db.size(); i++) {
                for (const std::string& key : test_read_db.keys()) {
                    if (data[i][key] != test_write_db[i][key]) return 1;
                }
            }

            return 0;
        }

        if (argc == 3) {
            utils::DatabaseFile test_read_db(argv[1], argv[2]);
            utils::DatabaseFile test_write_db("test/data/new3.dtb", argv[2]);

            if (test_read_db.empty()) return 1;
            test_read_db.unload(data);
            test_write_db.load(data);
            if (test_write_db.empty()) return 1;
            if (test_write_db.size() != test_read_db.size()) return 1;
            if (test_write_db.keys() != test_read_db.keys()) return 1;
            if (!test_write_db.write()) return 1;
            if (!test_write_db.write(data)) return 1;
            if (!test_write_db.write("test/data/new3.dtb", data)) return 1;

            for (size_t i = 0; i < test_read_db.size(); i++) {
                for (const std::string& key : test_read_db.keys()) {
                    if (data[i][key] != test_write_db[i][key]) return 1;
                }
            }

            return 0;
        }

        return 1;
    } catch (...) {
        return 1;
    }
}
