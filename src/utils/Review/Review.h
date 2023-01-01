#ifndef RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_REVIEW_H_
#define RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_REVIEW_H_
#include <iostream>

namespace utils {
  class Review {
    private:
      std::string id;
      std::string comment;
      int rating;

    public:
      Review(std::string id = "", std::string comment ="", int rating = 0) : id(id), comment(comment), rating(rating){};
      void show_review();
};
} // namespace utils


#endif//RMIT2022C_EEET2482_LODGING_APP_SRC_UTILS_REVIEW_REVIEW_H_