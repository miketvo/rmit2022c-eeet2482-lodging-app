#include <iostream>
#include <sstream>
#include "../../../src/utils/time/Datetime.h"

int main() {
    std::stringstream buffer;


    // =================================================================================================================
    // Datetime constructor tests
    //
    utils::time::Datetime now;
    std::cout << now.strf("now: %Y-%m-%d %H:%M:%S\n");

    utils::time::Datetime test1(std::time(nullptr));
    std::cout << test1.strf("test1: %Y-%m-%d %H:%M:%S\n");
    if (test1 != now) return 1;

    utils::time::Datetime test2(*std::localtime(new std::time_t(time(nullptr))));
    std::cout << test2.strf("test2: %Y-%m-%d %H:%M:%S\n");
    if (test2 != now) return 1;

    buffer << now.strf("%Y-%m-%d %H:%M:%S");
    utils::time::Datetime test3(buffer.str(), "%Y-%m-%d %H:%M:%S");
    std::cout << test3.strf("test3: %Y-%m-%d %H:%M:%S\n");
    if (test3 != now) return 1;
    // =================================================================================================================


    // =================================================================================================================
    // Datetime::set() tests
    //
    utils::time::Datetime test4;
    test4.set("2020-01-01 00:00:00", "%Y-%m-%d %H:%M:%S");
    std::cout << test4.strf("test4: %Y-%m-%d %H:%M:%S");
    if (test4 != utils::time::Datetime("2020-01-01 00:00:00", "%Y-%m-%d %H:%M:%S")) return 1;
    test4.set(*std::localtime(new std::time_t(time(nullptr))));
    std::cout << test4.strf(" <--> %Y-%m-%d %H:%M:%S\n");
    if (test4 != now) return 1;
    // =================================================================================================================


    utils::time::Datetime test5_start("2020-01-01 00:00:00", "%Y-%m-%d %H:%M:%S");
    utils::time::Datetime test5_end("2022-02-02 02:20:22", "%Y-%m-%d %H:%M:%S");
    utils::time::Period test5(test5_start, test5_end);
    std::cout << test5.days() << " days " << test5.hours() << " hours " << test5.minutes() << " minutes " << test5.seconds() << " seconds\n";
    if (test5.days() != 763 || test5.hours() != 2 || test5.hours() != 1 || test5.minutes() != 20 || test5.seconds() != 22) return 1;


    std::cout << "time.test: All tests passed.\n";
    return 0;
}