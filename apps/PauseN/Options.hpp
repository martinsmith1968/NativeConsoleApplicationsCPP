#pragma once

#include "AppDetails.h"
#include "CLI/CLI11.hpp"
#include "src/Strings.h"
#include <string>
#include <format>

using namespace std;
using namespace CLI;
using namespace DNX::Utilities;
using namespace AppDetails;

class Options
{
private:
    const string PLACEHOLDER_TIMEOUT = "{TIMEOUT}";
    const string PLACEHOLDER_SLEEP   = "{SLEEP}";

public:
    int TimeoutSeconds      = 30;
    int SleepMilliseconds   = 200;
    string MessageText = "Press any key to continue (or wait {timeout} seconds) . . . ";

    [[nodiscard]] string GetFormattedMessageText() const
    {
        return Strings::Replace(
                Strings::Replace(this->MessageText,
                                 PLACEHOLDER_TIMEOUT,
                                 to_string(this->TimeoutSeconds),
                                 false
                ),
                PLACEHOLDER_SLEEP,
                to_string(this->SleepMilliseconds),
                false
        );
    }

    static App Application;

    Options()
    {
        Application.set_help_all_flag("-?", "Print this help message and exit");
        Application.set_version_flag("-v,--version", APP_VERSION_HEADER + "\n" + APP_COPYRIGHT);

        Application.add_option("-m,--message-text", this->MessageText, "The text to Display (Use {timeout} and {sleep} for dynamic values)");
        Application.add_option("-t,--timeout", this->TimeoutSeconds, "The timeout to wait for in seconds");
        Application.add_option("-s,--sleep", this->SleepMilliseconds, "The time to sleep between checks in milliseconds");
    }
};

App Options::Application = App
{
    APP_HEADER,
    APP_NAME
};
