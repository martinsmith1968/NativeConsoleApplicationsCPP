#pragma once

#include <string>

// ReSharper disable CppInconsistentNaming

using namespace std;

namespace DNX::Utilities
{
    class FileSystemSettings
    {
    public:
        char DIRECTORY_SEPARATOR;
        char ALT_DIRECTORY_SEPARATOR;
        char PATH_SEPARATOR;
        char VOLUME_SEPARATOR;
        char FILE_EXTENSION_SEPARATOR;
        char* INVALID_PATH_CHARS;

        FileSystemSettings(char directorySeparator, char altDirectorySeparator, char pathSeparator, char volumeSeparator, char fileExtensionSeparator, char* invalidPathChars)
        {
            DIRECTORY_SEPARATOR       = directorySeparator;
            ALT_DIRECTORY_SEPARATOR   = altDirectorySeparator;
            PATH_SEPARATOR            = pathSeparator;
            VOLUME_SEPARATOR          = volumeSeparator;
            FILE_EXTENSION_SEPARATOR  = fileExtensionSeparator;
            INVALID_PATH_CHARS        = invalidPathChars;
        }

        static const FileSystemSettings& Windows;
        static const FileSystemSettings& Linux;
        static const FileSystemSettings& Current;
    };

    //--------------------------------------------------------------------------
    // Class: FileUtils
    //--------------------------------------------------------------------------
    class FileUtils
    {
    public:
        static string GetFileNameOnly(const string& filePath, const FileSystemSettings& fileSystemSettings = FileSystemSettings::Current);

        static string GetFileNameAndExtension(const string& filePath, const FileSystemSettings& fileSystemSettings = FileSystemSettings::Current);

        static string ChangeFileExtension(const string& filePath, const string& fileExtension, const FileSystemSettings& fileSystemSettings = FileSystemSettings::Current);

        static bool FileExists(const string& Filename);
    };
}
