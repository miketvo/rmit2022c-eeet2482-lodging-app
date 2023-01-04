add_custom_target(all-tests)

add_dependencies(
    all-tests

    DatabaseFile.test
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
    DatabaseFile.test EXCLUDE_FROM_ALL
    utils/io/DatabaseFile.test.cpp
    ../src/utils/io/DatabaseFile.cpp ../src/utils/io/DatabaseFile.h
    ../src/utils/io/corrupted_database.cpp ../src/utils/io/corrupted_database.h
)
