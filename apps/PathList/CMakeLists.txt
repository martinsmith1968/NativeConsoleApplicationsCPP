include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/cpp_defaults.cmake")

BeginProjectCPP(PathList 1.3 "Display the defined directories of PATH")
SetProjectCompanyName("DNX Solutions")
SetProjectCopyright("Copyright (c) DNX Solutions 2001-{CURRENTYEAR}")
SetProjectIcon("assets/folder.ico")

WriteAppDetailsHeader()
WriteAppDetailsResources()

add_executable(${PROJECT_NAME})

CollectSourceFilesCPP()
CollectResourceFilesCPP()

# https://discourse.cmake.org/t/how-to-use-resource-files-rc-in-cmake/2628
target_sources(${PROJECT_NAME} PRIVATE ${source_files})
target_sources(${PROJECT_NAME} PRIVATE ${resource_files})

target_link_libraries(
    ${PROJECT_NAME}
    dnx_utilities
)
