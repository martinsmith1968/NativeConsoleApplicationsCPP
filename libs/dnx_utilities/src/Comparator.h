#pragma once

#include <string>

using namespace std;

namespace DNX::Utilities
{
    class Comparator
    {
    public:
        template<typename K>
        static bool DefaultComparator(K first, K second)
        {
            return first == second;
        }

        static bool CaseInsensitiveStringComparator(const string& first, const string& second);
    };
}
