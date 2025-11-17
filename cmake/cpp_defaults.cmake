include("${CMAKE_SOURCE_DIR}/cmake/cpp_common.cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -Os")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

set(wxBUILD_SHARED OFF)
set(wxBUILD_USE_STATIC_RUNTIME ON)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/Output/${CMAKE_BUILD_TYPE}")

#set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(LIBRARY_OUTPUT_PATH    "${CMAKE_CURRENT_SOURCE_DIR}/lib/${CMAKE_BUILD_TYPE}")

include_directories("${CMAKE_SOURCE_DIR}/libs")
include_directories("${CMAKE_SOURCE_DIR}/libs/dnx_utilities")
include_directories("${CMAKE_SOURCE_DIR}/extern")

link_directories("${CMAKE_SOURCE_DIR}/libs")
