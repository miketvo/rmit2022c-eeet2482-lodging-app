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
    src/utils/io/corrupted_database.cpp src/utils/io/corrupted_database.h
    src/utils/time/Temporal.cpp src/utils/time/Temporal.h
    src/utils/time/Datetime.cpp src/utils/time/Datetime.h
    src/utils/time/Duration.cpp src/utils/time/Duration.h
    src/utils/time/Period.cpp src/utils/time/Period.h
)


#=======#
# TESTS #
#=======#
enable_testing()
add_subdirectory(test)

## Black box tests
add_test(main.test lodging)

## Unit tests
add_test(io.test test/io.test)
add_test(io.data.csv.test test/io.test test/data/bos2021ModC.csv)
add_test(io.data.tsv.test test/io.test test/data/bos2021ModC.tsv "\t")
add_test(io.data.psv.test test/io.test test/data/bos2021ModC.dat "|")
add_test(io.data.corrupted-dtb.test test/io.test test/data/corrupted.dtb)  # Throws utils::exceptions::corrupted_database
add_test(time.test test/time.test)

set_property(TEST io.data.corrupted-dtb.test PROPERTY WILL_FAIL true)
