cmake_minimum_required(VERSION 3.10)
project(rmit2022c_eeet2482_lodging_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    lodging
    src/main.cpp
)


#=======#
# TESTS #
#=======#
enable_testing()
add_subdirectory(test)

add_test(main.test lodging)
