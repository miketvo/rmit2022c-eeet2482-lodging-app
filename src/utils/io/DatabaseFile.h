#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_

#include <fstream>
#include <map>
#include <vector>

#define QUOTE '\"'

namespace utils {
    namespace io {
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
         *  <li>Recognizes quoted fields.</li>
         *  <li>Quoted field always use quote <code><strong>"</strong></code> character.</li>
         *  <li>Automatic quoted fields when writing to disk.</li>
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
            std::string auto_quoted_field(const std::string &str);

          public:
            /**
             * @brief Creates a DatabaseFile object,
             * @param path Path of the associated file on disk, defaults to "" (no associated file).
             * @param delim Delimiter to be used, defaults to ",".
             *
             * Creates a DatabaseFile object and associate it with a file on disk. Does not open and read the associated
             * file in @a path file (see open()).
             */
            explicit DatabaseFile(const std::string &path = "", const std::string &delim = ",");

            /**
             * @brief Reads data into this DatabaseFile from its associated file.
             * @return true if data have been read successfully, false if this DatabaseFile doesn't have an associated file.
             * @throw std::fstream::failure if file I/O operation failed.
             * @throw utils::io::exceptions::corrupted_database if encounters a malformed database entry.
             */
            bool read();

            /**
             * @brief Reads data into this DatabaseFile from a file in @a path.
             * @param path New file to be associated with this DatabaseFile, overwrites any old association.
             * @return true if data have been read successfully, false if this DatabaseFile does have an associated file.
             * @throw std::fstream::failure if file I/O operation failed.
             * @throw utils::io::exceptions::corrupted_database if encounters a malformed database entry.
             */
            bool read(const std::string &path);

            /**
             * @brief Writes data from this DatabaseFile into its associated file.
             * @return true if data have been written successfully, false if this DatabaseFile does not contain any data.
             * @throw std::fstream::failure if file I/O operation failed.
             */
            bool write();

            /**
             * @brief Store new @a data into this DatabaseFile then write into its associated file.
             * @param data New data to be stored into this DatabaseFile, overwrites any existing data.
             * @return true if data have been written successfully, false if this DatabaseFile does not contain any data.
             * @throw std::fstream::failure if file I/O operation failed.
             */
            bool write(std::vector<std::map<std::string, std::string>> &data);

            /**
              * @brief Store new @a data into this DatabaseFile then write it into a file in @a path.
              * @param data New data to be stored into this DatabaseFile, overwrites any existing data.
              * @param path New file to be associated with this DatabaseFile, overwrites any old association and overwrites
              * any existing data.
              * @return true if data have been written successfully, false if this DatabaseFile does not contain any data.
              * @throw std::fstream::failure if file I/O operation failed.
              */
            bool write(const std::string &path, std::vector<std::map<std::string, std::string>> &data);

            /**
             * @brief Loads data from <strong><code>source</code></strong> into this object, will overwrite any existing
             * data.
             * @param source data to be loaded.
             */
            void load(std::vector<std::map<std::string, std::string>> &source);

            /**
             * @brief Unload data from this object into <strong><code>dest</code></strong>
             * @param dest destination for data to be unloaded into, will overwrite any existing data.
             */
            void unload(std::vector<std::map<std::string, std::string>> &dest);

            // Provides easy load syntax. See load().
            void operator<<(std::vector<std::map<std::string, std::string>> &source);

            // Provides easy unload syntax. See unload().
            void operator>>(std::vector<std::map<std::string, std::string>> &dest);

            // Returns the number of records in the %DatabaseFile
            size_t size();

            // Returns true if this %DatabaseFile is empty
            bool empty();

            // Returns all keys from this database as a std::vector<std::string> vector, if there is no key, returns an
            // empty vector
            std::vector<std::string> keys();

            /**
             * @brief Subscript access to the data contained in the %DatabaseFile.
             * @param index The index of the element for which data should be accessed.
             * @return Read/write reference to data.
             *
             * This operator allows for easy, array-style, data access.Note that data access with this operator is unchecked
             * and out_of_range lookups are not defined. (For checked lookups see at().)
             */
            std::map<std::string, std::string> &operator[](size_t index);

            /**
             *  @brief Provides access to the data contained in the %DatabaseFile.
             *  @param index The index of the element for which data should be accessed.
             *  @return Read/write reference to data.
             *  @throw std::out_of_range If @a index is an invalid index.
             *
             *  This function provides for safer data access. The parameter is first checked that it is in the range of the
             *  DatabaseFile. The function throws out_of_range if the check fails.
             */
            std::map<std::string, std::string> &at(size_t index);

            std::string get_delim();
            void set_delim(const std::string &val);

            // Get the filepath associated with this DatabaseFile
            std::string get_path();

            // Associate a file on disk with this DatabaseFile
            void set_path(const std::string &val);
        };

    } // io
} // utils

#endif //RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_IO_DATABASEFILE_H_
