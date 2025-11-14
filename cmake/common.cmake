########################################################################################################################
## Functions
########################################################################################################################

function(BannerLine)
    message("************************************************************************************************************************")
endfunction()

function(BannerMessage text)
    message("** ${text}")
endfunction()

function(BannerStart text)
    BannerLine()
    BannerMessage("${text}")
endfunction()

function(BannerEnd)
    BannerLine()
endfunction()

function(Banner text)
    BannerStart("${text}")
    BannerEnd()
endfunction()


function(SectionLine)
    message("------------------------------------------------------------------------------------------------------------------------")
endfunction()

function(SectionMessage text)
    message("-- ${text}")
endfunction()

function(SectionStart text)
    SectionLine()
    SectionMessage("${text}")
endfunction()

function(SectionEnd)
    SectionLine()
endfunction()

function(Section text)
    SectionStart("${text}")
    SectionEnd()
endfunction()


function(Start task)
    Banner("Starting: ${task}")
endfunction()

function(StartProject)
    SectionLine()
    SectionMessage("Project     : ${PROJECT_NAME}")
    SectionMessage("Version     : ${PROJECT_VERSION}")
    SectionMessage("Description : ${PROJECT_DESCRIPTION}")
    SectionLine()
    SectionMessage("PROJECT_SOURCE_DIR       : ${PROJECT_SOURCE_DIR}")
    SectionMessage("EXECUTABLE_OUTPUT_PATH   : ${EXECUTABLE_OUTPUT_PATH}")
    SectionMessage("LIBRARY_OUTPUT_PATH      : ${LIBRARY_OUTPUT_PATH}")
    SectionMessage("CMAKE_CURRENT_BINARY_DIR : ${CMAKE_CURRENT_BINARY_DIR}")
    SectionLine()
endfunction()

function(ShowFiles typeName files)
    foreach(file IN ITEMS ${files})
        message(STATUS "Found ${typeName} : [${PROJECT_NAME}] ${file}")
    endforeach()
endfunction()


########################################################################################################################
## Macros
########################################################################################################################

macro(StatusMessage text)
    message(STATUS "${text}")
endmacro()

macro(SetOSInfo)
    # https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-To-Write-Platform-Checks
    set(OSWindows 0)
    set(OSLinux 0)
    set(OSMacOS 0)
    set(OSDescription "")

    if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows" OR ${CMAKE_SYSTEM_NAME} STREQUAL "MSYS")
        set(OSWindows 1)
        BannerMessage("Windows - ${CMAKE_SYSTEM}")
    endif()
    if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
        set(OSLinux 1)
        BannerMessage("Linux - ${CMAKE_SYSTEM}")
    endif()
    if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
        set(OSMacOS 1)
        BannerMessage("MacOS - ${CMAKE_SYSTEM}")
    endif()
endmacro()


########################################################################################################################
## Initialisation
########################################################################################################################
BannerStart("CMake v${CMAKE_VERSION} : ${PROJECT_NAME} [${CMAKE_HOST_SYSTEM_NAME} ${CMAKE_HOST_SYSTEM_PROCESSOR} - ${CMAKE_SYSTEM})")
SetOSInfo()
BannerMessage("${CMAKE_CURRENT_SOURCE_DIR}")
BannerEnd()
