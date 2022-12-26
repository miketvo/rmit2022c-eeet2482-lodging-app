#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_

#include <fstream>
#include <map>
#include <vector>

namespace utils {

    /**
     *
     * <p>
     * Utility class for saving a Vector of HashMaps into a delimiter-separated database text file and vice-versa. Uses
     * comma <code><strong>","</strong><code> as the default delimiter. Saved file always has first line containing keys
     * and subsequent lines containing values.
     * </p>
     *
     * <p>
     * Can skip through blank lines when reading database file.
     * </p>
     *
     */
    class DatabaseFile {
      private:
        std::string path, delim;
        std::vector<std::map<std::string, std::string>> data;
        std::fstream file;

      public:
        DatabaseFile();
        explicit DatabaseFile(const std::string &delim = ",");
        explicit DatabaseFile(const std::string &path, const std::string &delim = ",");

        bool open();
        bool open(const std::string &path);
        bool write(std::vector<std::map<std::string, std::string>> &data);
        bool write(const std::string &path, std::vector<std::map<std::string, std::string>> &data);

        size_t size();
        bool empty();
        std::vector<std::string> keys();

        std::map<std::string, std::string> get(size_t index);
        std::string get_delim();
        void set_delim(const std::string &val);
    };

} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_
