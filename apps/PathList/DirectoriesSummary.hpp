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

class DirectoriesSummary
{
private:
    list<string> NonExistantDirectories;
    list<string> DuplicateDirectories;
    int          EmptyDirectoriesCount = 0;

public:
    void AddNonExistantDirectory(const string& directory)
    {
        this->NonExistantDirectories.push_back(directory);
        this->NonExistantDirectories.unique();
    }

    void AddDuplicateDirectory(const string& directory)
    {
        this->DuplicateDirectories.push_back(directory);
        this->DuplicateDirectories.unique();
    }

    void AddEmptyDirectory(const string& directory)
    {
        this->EmptyDirectoriesCount++;
    }

    [[nodiscard]] list<string> SummaryMessages(bool showAll) const
    {
        list<string> summaries;

        if (showAll || this->NonExistantDirectories.size() > 0)
            summaries.push_back(to_string(this->NonExistantDirectories.size()) + " directories that do not exist");
        if (showAll || this->DuplicateDirectories.size() > 0)
            summaries.push_back(to_string(this->DuplicateDirectories.size()) + " duplicate directories");
        if (showAll || this->EmptyDirectoriesCount > 0)
            summaries.push_back(to_string(this->EmptyDirectoriesCount) + " empty directories");

        return summaries;
    }

    bool HasAlerts() const
    {
        return this->NonExistantDirectories.size() > 0
            || this->DuplicateDirectories.size() > 0
        ;
    }
};
