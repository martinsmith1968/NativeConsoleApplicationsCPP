include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

SectionStart("Configuring : plog")

set(downloadFileVersionName "1.1.10.zip")
set(targetDownloadDirectory "${CMAKE_CURRENT_SOURCE_DIR}/download")
set(targetDownloadFileName "${targetDownloadDirectory}/${downloadFileVersionName}")
set(targetExtractDirectory "${targetDownloadDirectory}/plog-1.1.10/include/plog/")

file(MAKE_DIRECTORY
        ${targetDownloadDirectory}
)

if(NOT EXISTS "${targetDownloadFileName}")
    StatusMessage("Downloading : ${downloadFileVersionName}")
    file(DOWNLOAD
            "https://github.com/SergiusTheBest/plog/archive/refs/tags/${downloadFileVersionName}"
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
        "${targetExtractDirectory}"
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}"
        NO_SOURCE_PERMISSIONS
        PATTERN "*.*"
)

SectionEnd()
