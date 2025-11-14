include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

SectionStart("Configuring : CLI11")

set(downloadFileVersionName "CLI11.hpp")
set(targetDownloadDirectory "${CMAKE_CURRENT_SOURCE_DIR}")
set(targetDownloadFileName "${targetDownloadDirectory}/${downloadFileVersionName}")

if(NOT EXISTS "${targetDownloadFileName}")
    StatusMessage("Downloading : ${downloadFileVersionName}")
    file(DOWNLOAD
            "https://github.com/CLIUtils/CLI11/releases/download/v2.3.2/CLI11.hpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/CLI11.hpp"
            STATUS fileStatus
    )
    StatusMessage("File Status : ${fileStatus}")
endif()

SectionEnd()
