#include "DatabaseFile.h"

namespace utils {
    DatabaseFile::DatabaseFile(const std::string &delim) {
        this->path = "";
        this->delim = delim;
    }

    DatabaseFile::DatabaseFile(const std::string &path, const std::string &delim) {
        this->path = path;
        this->delim = delim;
        this->open(this->path);
    }


    bool DatabaseFile::open() {
        return false;
    }

    bool DatabaseFile::open(const std::string &path) {
        this->path = path;
        return this->open();
    }

    bool DatabaseFile::write(std::vector<std::map<std::string, std::string>> &data) {
        return false;
    }

    bool DatabaseFile::write(const std::string &path, std::vector<std::map<std::string, std::string>> &data) {
        this->path = path;
        return this->write(data);
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
        return this->data.at(index);
    }


    std::string DatabaseFile::get_delim() {
        return this->delim;
    }

    void DatabaseFile::set_delim(const std::string &val) {
        this->delim = val;
    }
} // utils