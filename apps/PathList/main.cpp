#include "Options.hpp"
#include "DirectoriesSummary.hpp"

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// main
int main(const int argc, char* argv[])
{
    int returnCode = 0;

    Options options(argv[0]);
    CLI11_PARSE(options.Application, argc, argv);

    DirectoriesSummary summary;

    // Initialise
    if (options.OutputHeader)
    {
        cout << APP_HEADER << std::endl;
        cout << APP_COPYRIGHT << std::endl;
        cout << std::endl;
    }

    // Start
    auto environmentVariableValue = std::getenv(options.EnvironmentVariableName.c_str());
    if (!environmentVariableValue)
    {
        cerr << std::endl << "ERROR: Environment variaable: " << options.EnvironmentVariableName << " not found" << std::endl;
        return 2;
    }

    auto elements = Strings::SplitText(environmentVariableValue, options.PathSeparator);
    auto elementCount = elements.size();
    int indexPadSize = (int)(to_string(elementCount).size());

    if (elementCount > 0)
    {
        // Show All Directories
        auto index = 0;
        for (auto &element: elements)
        {
            ++index;

            char indicator = ' ';
            if (Strings::Trim(element).empty())
            {
                indicator = options.EmptyIndicator;
                summary.AddEmptyDirectory(element);
            }
            else if (!std::filesystem::is_directory(element))
            {
                indicator = options.NotExistsIndicator;
                summary.AddNonExistantDirectory(element);
            }
            else if (std::count(elements.begin(), elements.end(), element) > 1)
            {
                indicator = options.DuplicateIndicator;
                summary.AddDuplicateDirectory(element);
            }

            cout << std::setfill(' ') << std::setw(indexPadSize) << index
                 << indicator
                 << element
                 << std::endl;
        }
    }

    // Summary
    bool showSummary = (options.ShowSummaryType == Always)
            || (options.ShowSummaryType == Auto && summary.HasAlerts());
    if (showSummary)
    {
        cout << std::endl;
        cout << "Summary" << std::endl;

        auto showAll = options.ShowSummaryType == Always;

        for (auto &summaryText : summary.SummaryMessages(showAll))
        {
            cout << summaryText << std::endl;
        }
    }

    if (summary.HasAlerts())
        returnCode = 1;

    return returnCode;
}
