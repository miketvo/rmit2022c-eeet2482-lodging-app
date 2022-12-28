cmake_minimum_required(VERSION 3.10)
project(rmit2022c_eeet2482_lodging_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    lodging
    src/main.cpp
    src/Application.cpp src/Application.h
    src/entities/House.cpp src/entities/House.h src/entities/Member.cpp src/entities/Member.h
    src/entities/Admin.cpp src/entities/Admin.h src/entities/Account.cpp src/entities/Account.h
)


#=======#
# TESTS #
#=======#
enable_testing()
add_subdirectory(test)

add_test(main.test lodging)
