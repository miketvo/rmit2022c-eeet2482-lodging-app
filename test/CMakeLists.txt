add_custom_target(all-tests)
add_dependencies(all-tests
    io.test
    time.test
    houses.test
    lodging
)

## Prebuild task: Copy test files into build folder
add_custom_command(
    TARGET all-tests PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/test/data/ ${CMAKE_BINARY_DIR}/test/data/
)

## Test targets
add_executable(
    io.test EXCLUDE_FROM_ALL
    utils/io/io.test.cpp
    ../src/utils/io/DatabaseFile.cpp ../src/utils/io/DatabaseFile.h
    ../src/utils/io/corrupted_database.cpp ../src/utils/io/corrupted_database.h
)
add_executable(
    time.test EXCLUDE_FROM_ALL
    utils/time/time.test.cpp
    ../src/utils/time/Temporal.cpp ../src/utils/time/Temporal.h
    ../src/utils/time/Datetime.cpp ../src/utils/time/Datetime.h
    ../src/utils/time/Duration.cpp ../src/utils/time/Duration.h
    ../src/utils/time/Period.cpp ../src/utils/time/Period.h
)
add_executable(
        houses.test EXCLUDE_FROM_ALL
        houses/houses.test.cpp
        ../src/entities/house/House.cpp ../src/entities/house/House.h
        ../src/entities/house/HouseListing.cpp ../src/entities/house/HouseListing.h
        ../src/entities/house/HouseOccupancy.cpp ../src/entities/house/HouseOccupancy.h
        ../src/entities/house/HouseRequest.cpp ../src/entities/house/HouseRequest.h
)