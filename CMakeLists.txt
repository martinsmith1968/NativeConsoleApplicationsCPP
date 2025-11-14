cmake_minimum_required(VERSION 3.26)
project(NativeConsoleApps)

include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

add_subdirectory("extern")
add_subdirectory("libs")
add_subdirectory("apps")

Banner("Finished!")
