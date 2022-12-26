#include "../../../src/utils/io/DatabaseFile.h"

int main() {
    try {
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

        if (!test_db.open("data/bos2021ModC.csv")) return 1;
        if (!test_db.open("data/bos2021ModC.tsv")) return 1;
        if (!test_db.open("data/bos2021ModC.dat")) return 1;

        return 0;
    } catch (...) {
        return 1;
    }
}
