#pragma once

#include "AppDetails.h"
#include "CLI/CLI11.hpp"
#include "src/Strings.h"
#include "src/FileUtils.h"
#include <string>
#include <format>

using namespace std;
using namespace CLI;
using namespace DNX::Utilities;
using namespace AppDetails;

enum ShowSummaryType
{
    Never = 0,
    Always,
    Auto,
};

std::map<std::string, ShowSummaryType> ShowSummaryTypeMap{
        { "None", ShowSummaryType::Never },
        { "Always", ShowSummaryType::Always },
        { "Auto", ShowSummaryType::Auto },
};

class Options
{
private:
    const string PLACEHOLDER_NAME_PATH     = "PATH";
    const char DEFAULT_PATH_SEPARATOR      = FileSystemSettings::Current.PATH_SEPARATOR;
    const char DEFAULT_DUPLICATE_INDICATOR = '~';
    const char DEFAULT_NOTEXISTS_INDICATOR = '*';
    const char DEFAULT_EMPTY_INDICATOR     = '!';

public:
    string EnvironmentVariableName  = PLACEHOLDER_NAME_PATH;
    char PathSeparator              = DEFAULT_PATH_SEPARATOR;
    bool OutputHeader               = true;
    bool CheckForDuplicates         = true;
    bool CheckForDirectoryExists    = true;
    char NotExistsIndicator         = DEFAULT_NOTEXISTS_INDICATOR;
    char DuplicateIndicator         = DEFAULT_DUPLICATE_INDICATOR;
    char EmptyIndicator             = DEFAULT_EMPTY_INDICATOR;
    ShowSummaryType ShowSummaryType = Auto;

    static App Application;

    explicit Options(char* programName)
    {
        auto configFileName = APP_NAME + ".config";

        auto programPath = filesystem::path(programName).parent_path().string();

        Application.set_help_all_flag("-?", "Print this help message and exit");
        Application.set_version_flag("-v,--version", APP_VERSION_HEADER + "\n" + APP_COPYRIGHT);

        Application.set_config("-@,--config", configFileName, "Stored config options file (TOML format)", false)
                   ->transform(CLI::FileOnDefaultPath(programPath, false))
                   ->transform(CLI::FileOnDefaultPath(".", false))
                   ;
        Application.option_defaults()
                   ->configurable(true)
                   ;

        Application.add_option("name,-n,--name", this->EnvironmentVariableName, "The environment variable name to parse (Default: '" + PLACEHOLDER_NAME_PATH + "')");
        Application.add_option("-s,--separator", this->PathSeparator, "The separator between values (Default: " + Strings::ToString(DEFAULT_PATH_SEPARATOR) + ")");
        Application.add_flag("-p,--output-header,!--no-header", this->OutputHeader, "Output the Application Header")
            ->default_val(true);
        Application.add_flag("-x,--existance-check,!--no-existance-check", this->CheckForDirectoryExists, "Check each defined directory exists")
            ->default_val(true);
        Application.add_flag("-c,--duplicate-check,!--no-duplicate-check", this->CheckForDuplicates, "Check for duplicate defined directories")
            ->default_val(true);
        Application.add_option("-d,--duplicate-indicator", this->DuplicateIndicator, "The indicator when a directory is a duplicate (Default: '" + Strings::ToString(DEFAULT_DUPLICATE_INDICATOR) + "')");
        Application.add_option("-i,--notexists-indicator", this->NotExistsIndicator, "The indicator when a directory does not exist (Default: '" + Strings::ToString(DEFAULT_NOTEXISTS_INDICATOR) + "')");
        Application.add_option("-e,--empty-indicator", this->EmptyIndicator, "The indicator when a directory entry is empty / blank (Default: '" + Strings::ToString(DEFAULT_EMPTY_INDICATOR) + "')");
        Application.add_option("-y,--summary-display", this->ShowSummaryType, "Control the Summary display")
            ->default_val(ShowSummaryType::Auto)
            ->transform(CLI::CheckedTransformer(ShowSummaryTypeMap, CLI::ignore_case));
    }
};

App Options::Application = App
{
    APP_HEADER,
    APP_NAME
};
