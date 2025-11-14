include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/cpp_defaults.cmake")

BeginProjectCPP(GUIDGen 1.0 "Generate GUIDs, optionally with formatting")
SetProjectCompanyName("DNX Solutions")
SetProjectCopyright("Copyright (c) DNX Solutions 2011-{CURRENTYEAR}")

WriteAppDetailsHeader()
WriteAppDetailsResources()

add_executable(${PROJECT_NAME})

CollectSourceFilesCPP()
CollectResourceFilesCPP()

# https://discourse.cmake.org/t/how-to-use-resource-files-rc-in-cmake/2628
target_sources(${PROJECT_NAME} PRIVATE ${source_files})
target_sources(${PROJECT_NAME} PRIVATE ${resource_files})

include_directories("${CMAKE_SOURCE_DIR}/extern/stduuid")
#include_directories("${CMAKE_SOURCE_DIR}/extern/boost")

target_link_libraries(
        ${PROJECT_NAME}
        dnx_utilities
)
