#include <iomanip>
#include "DatabaseFile.h"

namespace utils {
    std::vector<std::string> DatabaseFile::tokenize(const std::string &str) {
        std::vector<std::string> tokens;
        size_t token_start = 0, token_end = 0;

        while (token_end != std::string::npos) {
            token_end = str.find(this->delim, token_start);
            tokens.push_back(str.substr(token_start, token_end - token_start));
            token_start = token_end + this->delim.length();
        }

        return tokens;
    }


    DatabaseFile::DatabaseFile() {
        this->path = "";
        this->delim = ",";
    }

    DatabaseFile::DatabaseFile(const std::string &path, const std::string &delim) {
        this->path = path;
        this->delim = delim;
        this->open(this->path);
    }


    bool DatabaseFile::open() {
        this->file.open(this->path, std::ios::in);
        if (!this->file.is_open()) return false;  // TODO: Throw error here for "unable to read database"

        std::string buffer;

        // Read keys
        std::getline(this->file, buffer);
        if (buffer.empty()) return false;  // TODO: Throw error here for "corrupted database"
        std::vector<std::string> keys = this->tokenize(buffer);

        // Read values
        std::vector<std::string> values;
        while (std::getline(this->file, buffer)) {
            if (!buffer.empty()) {
                values = this->tokenize(buffer);
                if (keys.size() != values.size()) return false;  // TODO: Throw error here for "corrupted database"

                std::map<std::string, std::string> record;
                for (size_t i = 0; i < keys.size(); i++) {
                    record.emplace(keys[i], values[i]);
                }
            }
        }

        return true;
    }

    bool DatabaseFile::open(const std::string &path) {
        this->path = path;
        return this->open();
    }

    void DatabaseFile::load(std::vector<std::map<std::string, std::string>> &data) {
        this->data = data;
    }

    void DatabaseFile::unload(std::vector<std::map<std::string, std::string>> &data) {
        data = this->data;
    }

    bool DatabaseFile::write() {
        std::string buffer;
        std::vector<std::string> keys;

        this->file.open(this->path, std::ios::out);
        if (!this->file.is_open()) return false;  // TODO: Throw error here for "unable to write database"

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


    std::string DatabaseFile::get_delim() {
        return this->delim;
    }

    void DatabaseFile::set_delim(const std::string &val) {
        this->delim = val;
    }


    std::map<std::string, std::string> DatabaseFile::operator[](size_t index) {
        return this->get(index);
    }
} // utils