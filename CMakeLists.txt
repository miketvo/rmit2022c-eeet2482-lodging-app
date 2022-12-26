cmake_minimum_required(VERSION 3.10)
project(rmit2022c_eeet2482_lodging_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    lodging
    src/main.cpp
    src/utils/io/DatabaseFile.cpp src/utils/io/DatabaseFile.h
)


#=======#
# TESTS #
#=======#
enable_testing()
add_subdirectory(test)

add_test(main.test lodging)
add_test(DatabaseFile.test test/DatabaseFile.test)
