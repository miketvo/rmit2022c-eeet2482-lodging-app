add_custom_target(all-tests)

add_dependencies(
    all-tests
    lodging
)

# Copy test files into build folder
add_custom_command(TARGET all-tests PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/test/data/ ${CMAKE_BINARY_DIR}/test/data/
)
