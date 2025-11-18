cmake_minimum_required(VERSION 4.0.2)
project(NativeConsoleApps)

# Style Guides:
# - https://cmake.org/cmake/help/book/mastering-cmake/chapter/Writing%20CMakeLists%20Files.html
# - https://docs.zephyrproject.org/latest/contribute/style/cmake.html
# - https://community.kde.org/Policies/CMake_Coding_Style

include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

add_subdirectory("extern")
add_subdirectory("libs")
add_subdirectory("apps")

Banner("Finished!")
