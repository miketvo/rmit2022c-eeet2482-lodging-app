#include <sstream>
#include "DatabaseFile.h"
#include "corrupted_database.h"

namespace utils {
    std::vector<std::string> DatabaseFile::tokenize(const std::string &str) {
        bool quoted_field = false;
        std::vector<std::string> tokens;
        size_t token_start = 0, token_end = 0;

        while (token_end != std::string::npos) {
            if (str[token_start] == QUOTE) quoted_field = true;
            if (quoted_field) {
                while (quoted_field) {
                    // Start quoted tokenization
                    token_end = str.find(this->delim, token_end + this->delim.length());
                    if (str[token_end - 1] == QUOTE && str[token_end - 2] != '\\') {
                        token_start++;  // Discard the left quote
                        token_end--;    // Discard the right quote
                        tokens.push_back(str.substr(token_start, token_end - token_start));  // Get quoted field

                        // Resume normal tokenization
                        quoted_field = false;
                        token_end++;
                    }
                }
            } else {
                token_end = str.find(this->delim, token_start);
                tokens.push_back(str.substr(token_start, token_end - token_start));  // Get field
            }

            token_start = token_end + this->delim.length();  // Move to next token
        }

        return tokens;
    }

    std::string DatabaseFile::auto_quoted_field(const std::string &str) {
        if (str.find(this->delim) != std::string::npos) {
            return '"' + str + '"';
        }

        return str;
    }


    DatabaseFile::DatabaseFile() {
        this->path = "";
        this->delim = ",";
        this->file.exceptions( std::ios::failbit | std::ios::badbit );
    }

    DatabaseFile::DatabaseFile(const std::string &path, const std::string &delim) {
        this->path = path;
        this->delim = delim;
        this->file.exceptions( std::ios::failbit | std::ios::badbit );
    }


    bool DatabaseFile::open() {
        if (this->path.empty()) return false;

        this->file.open(this->path, std::ios::in);
        std::string buffer;

        // Read keys
        std::getline(this->file, buffer);
        if (buffer.empty()) throw exceptions::corrupted_database(this->path);
        std::vector<std::string> keys = this->tokenize(buffer);

        // Read values
        std::vector<std::string> values;
        while (std::getline(this->file, buffer)) {
            if (!buffer.empty()) {
                values = this->tokenize(buffer);
                if (keys.size() != values.size()) throw exceptions::corrupted_database(this->path);

                std::map<std::string, std::string> record;
                for (size_t i = 0; i < keys.size(); i++) {
                    record.emplace(keys[i], values[i]);
                }
                this->data.emplace_back(record);
            }
        }

        this->file.close();
        return true;
    }

    bool DatabaseFile::open(const std::string &path) {
        this->path = path;
        return this->open();
    }

    bool DatabaseFile::write() {
        if (this->data.empty()) return false;

        std::string buffer;
        this->file.open(this->path, std::ios::out);

        // Write header
        std::vector<std::string> keys = this->keys();
        for (size_t i = 0; i < keys.size(); i++) {
            file << this->auto_quoted_field(keys[i]) << (i + 1 == keys.size() ? "\n" : this->delim);
        }

        // Write records
        for (const auto &record : data) {
            size_t pair_count = 0;
            for (const auto& pair : record) {
                pair_count++;
                file << this->auto_quoted_field(pair.second) << (record.size() == pair_count ? "\n" : this->delim);
            }
        }

        this->file.close();
        return true;
    }

    bool DatabaseFile::write(std::vector<std::map<std::string, std::string>> &data) {
        this->data = data;
        return this->write();
    }

    bool DatabaseFile::write(const std::string &path, std::vector<std::map<std::string, std::string>> &data) {
        this->path = path;
        this->data = data;
        return this->write();
    }


    void DatabaseFile::load(std::vector<std::map<std::string, std::string>> &data) {
        this->data = data;
    }

    void DatabaseFile::unload(std::vector<std::map<std::string, std::string>> &data) {
        data = this->data;
    }

    void DatabaseFile::operator<<(std::vector<std::map<std::string, std::string>> &data) {
        this->load(data);
    }

    void DatabaseFile::operator>>(std::vector<std::map<std::string, std::string>> &data) {
        this->unload(data);
    }


    size_t DatabaseFile::size() {
        return this->data.size();
    }

    bool DatabaseFile::empty() {
        return this->data.empty();
    }

    std::vector<std::string> DatabaseFile::keys() {
        std::vector<std::string> result;
        if (!this->data.empty()) {
            for (
                const auto &pair : this->data.at(0)) {
                result.push_back(pair.first);
            }
        }
        return result;
    }

    std::map<std::string, std::string> DatabaseFile::get(size_t index) {
        return this->data[index];
    }

    std::map<std::string, std::string> DatabaseFile::operator[](size_t index) {
        return this->get(index);
    }


    std::string DatabaseFile::get_delim() {
        return this->delim;
    }

    void DatabaseFile::set_delim(const std::string &val) {
        this->delim = val;
    }

} // utils