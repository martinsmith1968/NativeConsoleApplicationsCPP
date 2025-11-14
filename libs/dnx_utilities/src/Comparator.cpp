#include "Comparator.h"

using namespace DNX::Utilities;

bool Comparator::CaseInsensitiveStringComparator(const string& first, const string& second)
{
    if (first.size() != second.size())
        return false;

    for (size_t i = 0; i < first.size(); ++i)
    {
        if (tolower(first[i]) != tolower(second[i]))
            return false;
    }

    return true;
}
