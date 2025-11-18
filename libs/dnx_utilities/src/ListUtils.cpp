#include "ListUtils.h"
#include <algorithm>
#include "Comparator.h"


using namespace DNX::Utilities;

list<string> ListUtils::ToList(const char **array)
{
    list<string> list;

    for (auto i = 0; i < sizeof(array); ++i) {
        list.emplace_back(array[i]);
    }

    return list;
}

bool ListUtils::IsOneOf(const string &value, const list<string>& values, bool caseSensitive)
{
    if (caseSensitive)
    {
        // From: https://stackoverflow.com/questions/36494584/find-string-in-vector-of-strings-case-insensitive-c
        auto predicate = [&](const string &s)
            {
                return Comparator::CaseInsensitiveStringComparator(s, value);
            };

        return std::find_if(values.begin(), values.end(), predicate) != values.end();
    }
    else
    {
        return std::find(values.begin(), values.end(), value) != values.end();
    }
}
