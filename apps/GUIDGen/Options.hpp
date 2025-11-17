#pragma once

#include "AppDetails.h"
#include "CLI/CLI11.hpp"
#include "src/Strings.h"
#include "GuidHelper.hpp"
#include <string>
#include <format>

using namespace std;
using namespace CLI;
using namespace DNX::Utilities;
using namespace AppDetails;

enum CaseConversionType
{
    None = 0,
    LowerCase,
    UpperCase
};

std::map<std::string, CaseConversionType> CaseConversionTypeMap{
    { "None", CaseConversionType::None },
    { "Lower", CaseConversionType::LowerCase },
    { "Upper", CaseConversionType::UpperCase },
};

std::map<std::string, GUIDGenerationModeType> GUIDGenerationModeTypeMap{
    { "Standard", GUIDGenerationModeType::Standard },
    { "Kashmir", GUIDGenerationModeType::Kashmir },
};

class Options
{
private:
    const string PLACEHOLDER_GUID  = "{GUID}";
    const string PLACEHOLDER_INDEX = "{INDEX}";

    [[nodiscard]] string FormatGUIDCase(string value) const
    {
        switch(CaseConversion)
        {
            case LowerCase:
                return Strings::ToLower(value);
            case UpperCase:
                return Strings::ToUpper(value);
            default:
                return value;
        }
    }

public:
    bool OutputHeader                     = true;
    unsigned int Count                    = 1;
    CaseConversionType CaseConversion     = CaseConversionType::None;
    GUIDGenerationModeType GenerationMode = GUIDGenerationModeType::Standard;
    string Delimiter                      = "\r\n";
    string Format                         = PLACEHOLDER_GUID;

    static App Application;

    Options()
    {
        auto configFileName = APP_NAME + ".config";

        Application.set_help_all_flag("-?", "Print this help message and exit");
        Application.set_version_flag("-v,--version", APP_VERSION_HEADER + "\n" + APP_COPYRIGHT);
        Application.set_config("-@,--config", configFileName, "A default config file", false)
            //->transform(CLI::FileOnDefaultPath("."));
            //->transform(FileOnExecutablePath())
            ;

        Application.add_flag("-p,--output-header,!--no-header", this->OutputHeader, "Output the Application Header")
                   ->default_val(true);

        Application.add_option("-n,--number", this->Count, "The number of GUIDs to generate")
            ->check(CLI::PositiveNumber, "Value must be a positive number");
        Application.add_option("-d,--delimiter", this->Delimiter, "The delimiter between generated GUIDs");
        Application.add_option("-f,--format", this->Format, "The format to use when displaying GUIDs. Use " + PLACEHOLDER_GUID + " for the actual value");
        Application.add_option("-c,--case", CaseConversion, "Set the case of the generated value")
           ->transform(CLI::CheckedTransformer(CaseConversionTypeMap, CLI::ignore_case));
        Application.add_option("-m,--mode", GenerationMode, "Define the generator algorithm to use")
           ->transform(CLI::CheckedTransformer(GUIDGenerationModeTypeMap, CLI::ignore_case));
    }

    [[nodiscard]] string FormatGUID(const string &guidText, const int index) const
    {
        auto value = Format;
        value = Strings::Replace(value, PLACEHOLDER_GUID, FormatGUIDCase(guidText));
        value = Strings::Replace(value, PLACEHOLDER_INDEX, to_string(index));
        return value;
    }
};

App Options::Application = App
{
    APP_HEADER,
    APP_NAME
};
