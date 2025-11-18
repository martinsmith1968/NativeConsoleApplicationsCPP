include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

SectionStart("Configuring : EasyLogging++")

set(downloadFileVersionName "v9.97.1.zip")
set(targetDownloadDirectory "${CMAKE_CURRENT_SOURCE_DIR}/download")
set(targetDownloadFileName "${targetDownloadDirectory}/${downloadFileVersionName}")
set(targetExtractDirectory "${targetDownloadDirectory}/easyloggingpp-9.97.1")

file(MAKE_DIRECTORY
        ${targetDownloadDirectory}
)

if(NOT EXISTS "${targetDownloadFileName}")
    StatusMessage("Downloading : ${downloadFileVersionName}")
    file(DOWNLOAD
            "https://github.com/abumq/easyloggingpp/archive/refs/tags/${downloadFileVersionName}"
            "${targetDownloadFileName}"
            STATUS fileStatus
    )
    StatusMessage("File Status : ${fileStatus}")
endif()

if(NOT EXISTS "${targetExtractDirectory}")
    StatusMessage("Extracting : ${targetDownloadFileName}")
    file(ARCHIVE_EXTRACT
            INPUT "${targetDownloadFileName}"
            DESTINATION "${targetDownloadDirectory}"
    )
endif()

file(INSTALL
        "${targetExtractDirectory}/src/"
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}"
        NO_SOURCE_PERMISSIONS
        PATTERN "*.*"
)

SectionEnd()
