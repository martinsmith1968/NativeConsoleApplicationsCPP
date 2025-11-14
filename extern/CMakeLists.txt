include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

add_subdirectory(boost)
add_subdirectory(CLI)
add_subdirectory(EasyLogging)
add_subdirectory(ooid)
add_subdirectory(plog)
add_subdirectory(stduuid)

if(NOT EXISTS ".gitignore")
    StatusMessage("Writing : .gitignore")
    file(GENERATE OUTPUT .gitignore CONTENT "download/")
endif()
