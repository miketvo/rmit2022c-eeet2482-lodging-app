cmake_minimum_required(VERSION 3.10)
project(rmit2022c_eeet2482_lodging_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    lodging
    src/main.cpp
    src/Application.cpp src/Application.h
    src/entities/house/House.cpp src/entities/house/House.h
    src/entities/house/HouseOccupancy.cpp src/entities/house/HouseOccupancy.h
    src/entities/house/HouseListing.cpp src/entities/house/HouseListing.h
    src/entities/house/OccupantReview.cpp src/entities/house/OccupantReview.h
    src/entities/account/HouseReview.h src/entities/account/HouseReview.cpp
    src/entities/account/Member.cpp src/entities/account/Member.h
    src/entities/account/Account.cpp src/entities/account/Account.h
    src/entities/account/Admin.cpp src/entities/account/Admin.h
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
