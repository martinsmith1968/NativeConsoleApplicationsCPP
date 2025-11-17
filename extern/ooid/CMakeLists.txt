include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

SectionStart("Configuring : OOID")

set(downloadFileVersionName "ooid-0.99.tar.gz")
set(targetDownloadDirectory "${CMAKE_CURRENT_SOURCE_DIR}/download")
set(targetDownloadFileName "${targetDownloadDirectory}/${downloadFileVersionName}")
set(targetExtractDirectory "${targetDownloadDirectory}/ooid")

file(MAKE_DIRECTORY
    ${targetDownloadDirectory}
)

if(NOT EXISTS "${targetDownloadFileName}")
    StatusMessage("Downloading : ${downloadFileVersionName}")
    file(DOWNLOAD
            "https://master.dl.sourceforge.net/project/ooid/${downloadFileVersionName}?viasf=1"
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
        "${targetExtractDirectory}/kashmir/"
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}"
        NO_SOURCE_PERMISSIONS
        PATTERN "*.*"
)

SectionEnd()
