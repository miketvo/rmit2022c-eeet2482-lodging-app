cmake_minimum_required(VERSION 3.10)
project(rmit2022c_eeet2482_lodging_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    lodging
    src/main.cpp
    src/Application.cpp src/Application.h
    src/entities/House.cpp src/entities/House.h src/entities/Member.cpp src/entities/Member.h
    src/entities/Admin.cpp src/entities/Admin.h src/entities/Account.cpp src/entities/Account.h
    src/utils/io/DatabaseFile.cpp src/utils/io/DatabaseFile.h
)


#=======#
# TESTS #
#=======#
enable_testing()
add_subdirectory(test)

## Black box tests
add_test(main.test lodging)

## Unit tests
add_test(DatabaseFile.test test/DatabaseFile.test)
add_test(DatabaseFile.data.csv.test test/DatabaseFile.test test/data/bos2021ModC.csv)
add_test(DatabaseFile.data.tsv.test test/DatabaseFile.test test/data/bos2021ModC.tsv "\t")
add_test(DatabaseFile.data.psv.test test/DatabaseFile.test test/data/bos2021ModC.dat "|")
