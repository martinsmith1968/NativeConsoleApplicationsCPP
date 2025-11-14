include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/cpp_defaults.cmake")


BeginProjectCPP(dnx_utilities 1.0 "DNX Utilities")
SetProjectCompanyName("DNX Solutions")
SetProjectCopyright("Copyright (c) DNX Solutions 2011-{CURRENTYEAR}")
project(dnx_utilities)

WriteAppDetailsHeader()
WriteAppDetailsResources()

add_library(${PROJECT_NAME})

CollectSourceFilesCPP()
CollectResourceFilesCPP()

# https://discourse.cmake.org/t/how-to-use-resource-files-rc-in-cmake/2628
target_sources(${PROJECT_NAME} PRIVATE ${source_files})
target_sources(${PROJECT_NAME} PRIVATE ${resource_files})

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Process Tests
#add_subdirectory("tests")
