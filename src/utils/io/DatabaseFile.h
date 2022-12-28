#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_

#include <fstream>
#include <map>
#include <vector>

#define QUOTE '\"'

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
     * Notes:
     * <ul>
     *  <li>Can skip through blank lines when reading database file.</li>
     *  <li>Not greedy, e.g. does not discard consecutive delimiters but treats them as empty fields.</li>
     *  <li>Quoted field always use quote <code><strong>"</strong></code> character.</li>
     * </ul>
     * </p>
     *
     */
    class DatabaseFile {
      private:
        std::string path, delim;
        std::vector<std::map<std::string, std::string>> data;
        std::fstream file;

      protected:
        std::vector<std::string> tokenize(const std::string &str);

      public:
        DatabaseFile();
        explicit DatabaseFile(const std::string &path, const std::string &delim = ",");

        bool open();
        bool open(const std::string &path);
        void load(std::vector<std::map<std::string, std::string>> &data);
        void unload(std::vector<std::map<std::string, std::string>> &data);
        bool write();
        bool write(std::vector<std::map<std::string, std::string>> &data);
        bool write(const std::string &path, std::vector<std::map<std::string, std::string>> &data);

        size_t size();
        bool empty();
        std::vector<std::string> keys();

        std::map<std::string, std::string> get(size_t index);
        std::string get_delim();
        void set_delim(const std::string &val);

        std::map<std::string, std::string> operator[](size_t index);
    };

} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_
