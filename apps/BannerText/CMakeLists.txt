include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/cpp_defaults.cmake")

BeginProjectCPP(BannerText 1.0 "Show Banner messages to the console")
CollectSourceFilesCPP()
WriteAppDetailsHeader()
WriteAppDetailsResources()

add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(
    ${PROJECT_NAME}
    dnx_utilities
)
