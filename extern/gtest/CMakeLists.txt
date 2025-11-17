include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

SectionStart("Configuring : GoogleTest")

#https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip

set(downloadFileVersionName "v1.17.0.zip")
set(targetDownloadDirectory "${CMAKE_CURRENT_SOURCE_DIR}/download")
set(targetDownloadFileName "${targetDownloadDirectory}/${downloadFileVersionName}")
set(targetExtractDirectory "${targetDownloadDirectory}/googletest-1.17.0")

file(MAKE_DIRECTORY
    ${targetDownloadDirectory}
)

if(NOT EXISTS "${targetDownloadFileName}")
    StatusMessage("Downloading : ${downloadFileVersionName}")
    file(DOWNLOAD
            "https://github.com/google/googletest/archive/refs/tags/${downloadFileVersionName}"
            "${targetDownloadFileName}"
            SHOW_PROGRESS
            STATUS fileStatus
    )
    StatusMessage("File Status : ${fileStatus}")
endif()

if(NOT EXISTS "${targetExtractDirectory}")
    StatusMessage("Extracting : ${targetDownloadFileName}")
    file(ARCHIVE_EXTRACT
            INPUT "${targetDownloadFileName}"
            DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/googlemock")
    StatusMessage("Installing : ${targetDownloadFileName} - GoogleMock")
    file(INSTALL
           "${targetExtractDirectory}/googlemock/"
            DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/googlemock"
            NO_SOURCE_PERMISSIONS
            PATTERN "*.*"
    )
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/googletest")
    StatusMessage("Installing : ${targetDownloadFileName} - GoogleTest")
    file(INSTALL
            "${targetExtractDirectory}/googletest/"
            DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
            NO_SOURCE_PERMISSIONS
            PATTERN "*.*"
    )
endif()


SectionEnd()
