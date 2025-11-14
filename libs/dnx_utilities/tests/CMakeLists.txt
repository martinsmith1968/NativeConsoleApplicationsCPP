# https://github.com/google/googletest/blob/v1.14.0/docs/quickstart-cmake.md

include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/cpp_defaults.cmake")


project(dnx_utilites_tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###############
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#######################


file(GLOB_RECURSE source_files
        "*.cpp"
)

foreach(source_file IN ITEMS ${source_files})
    message(STATUS "Found : [${PROJECT_NAME}] ${source_file}")
endforeach()

add_executable(${PROJECT_NAME} ${source_files})
target_link_libraries(
        ${PROJECT_NAME}
        GTest::gtest_main
        dnx_utilities
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

# Execute Tests
#add_custom_command(
#        TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${PROJECT_NAME}
#        COMMENT "Running Tests..."
#)

Banner("Running Tests")
add_custom_target(
    do_always
    ALL
    COMMAND ${PROJECT_NAME}
    COMMENT "Running Tests..."
    DEPENDS ${PROJECT_NAME}
)
