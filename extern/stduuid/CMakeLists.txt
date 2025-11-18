include("${CMAKE_SOURCE_DIR}/cmake/common.cmake")

Section("Downloading stduuid")

set(downloadFileVersionName "stduuid-1.2.3.zip")
set(targetDownloadDirectory "${CMAKE_CURRENT_SOURCE_DIR}/download")
set(targetDownloadFileName "${targetDownloadDirectory}/${downloadFileVersionName}")
set(targetExtractDirectory "${targetDownloadDirectory}/stduuid-1.2.3")

set(fileVersionName "stduuid-1.2.3.zip")
set(targetDirectory "${CMAKE_CURRENT_SOURCE_DIR}/download")
set(targetFileName "${targetDirectory}/${fileVersionName}")

file(MAKE_DIRECTORY
        ${targetDownloadDirectory}
)

if(NOT EXISTS ${targetDownloadFileName})
    StatusMessage("Downloading : ${downloadFileVersionName}")
    file(DOWNLOAD
            "https://github.com/mariusbancila/stduuid/archive/refs/tags/v1.2.3.zip"
            ${targetDownloadFileName}
            STATUS fileStatus
    )
    StatusMessage("File Status : ${fileStatus}")
endif()

if(NOT EXISTS "${targetExtractDirectory}")
    StatusMessage("Extracting : ${targetDownloadFileName}")
    file(ARCHIVE_EXTRACT
            INPUT ${targetDownloadFileName}
            DESTINATION "${targetDownloadDirectory}"
    )
endif()

file(INSTALL
        "${targetExtractDirectory}/include/"
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}"
        NO_SOURCE_PERMISSIONS
        PATTERN "*.*"
)
file(INSTALL
        "${targetExtractDirectory}/gsl/"
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/gsl"
        NO_SOURCE_PERMISSIONS
        PATTERN "*.*"
)

include_directories("${PROJECT_SOURCE_DIR}/gsl")
