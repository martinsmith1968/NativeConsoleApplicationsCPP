#include "FileUtils.h"

#include <io.h>
#define ACCESS    _access_s

using namespace DNX::Utilities;

char windowsInvalidPathChars[] = {
    '\u007C', '\u0000', '\u0001', '\u0002', '\u0003', '\u0004', '\u0005', '\u0006', '\u0007', '\u0008',
    '\u0009', '\u000A', '\u000B', '\u000C', '\u000D', '\u000E', '\u000F', '\u0010', '\u0011', '\u0012',
    '\u0013', '\u0014', '\u0015', '\u0016', '\u0017', '\u0018', '\u0019', '\u001A', '\u001B', '\u001C',
    '\u001D', '\u001E', '\u001F'

};
char linuxInvalidPathChars[] = {
    '\u0000'
};

FileSystemSettings* windowsFileSystemSettings = new FileSystemSettings(
        '\\',
        '/',
        ';',
        ':',
        '.',
        windowsInvalidPathChars
        );
const FileSystemSettings& FileSystemSettings::Windows = *windowsFileSystemSettings;

FileSystemSettings* linuxFileSystemSettings = new FileSystemSettings(
        '/',
        '/',
        ':',
        '/',
        '.',
        linuxInvalidPathChars
);
const FileSystemSettings& FileSystemSettings::Linux = *linuxFileSystemSettings;

#if defined(WIN32) || defined(WIN64) || defined(WINNT)
const FileSystemSettings& FileSystemSettings::Current = FileSystemSettings::Windows;
#else
const FileSystemSettings& FileSystemSettings::Current = FileSystemSettings::Linux;
#endif

string FileUtils::GetFileNameOnly(const string& filePath, const FileSystemSettings& fileSystemSettings)
{
    auto fileName = GetFileNameAndExtension(filePath);

    const auto lastFileExtSep = fileName.find_last_of(fileSystemSettings.FILE_EXTENSION_SEPARATOR);
    if (lastFileExtSep != string::npos)
    {
        fileName = fileName.substr(0, lastFileExtSep);
    }

    return fileName;
}

string FileUtils::GetFileNameAndExtension(const string& filePath, const FileSystemSettings& fileSystemSettings)
{
    auto fileName = filePath;

    const auto lastPathSep = filePath.find_last_of(fileSystemSettings.DIRECTORY_SEPARATOR);
    if (lastPathSep != string::npos)
    {
        fileName = filePath.substr(lastPathSep + 1);
    }

    return fileName;
}

string FileUtils::ChangeFileExtension(const string& filePath, const string& fileExtension, const FileSystemSettings& fileSystemSettings)
{
    auto fileName = filePath;

    const auto lastFileExtSep = fileName.find_last_of(fileSystemSettings.FILE_EXTENSION_SEPARATOR);
    if (lastFileExtSep != string::npos)
    {
        fileName = fileName.substr(0, lastFileExtSep);
    }

    if (fileExtension.length() > 0 && fileExtension[0] != fileSystemSettings.FILE_EXTENSION_SEPARATOR)
    {
        fileName += fileSystemSettings.FILE_EXTENSION_SEPARATOR;
    }

    fileName += fileExtension;

    return fileName;
}

bool FileUtils::FileExists(const string& Filename)
{
    return ACCESS(Filename.c_str(), 0) == 0;
}
