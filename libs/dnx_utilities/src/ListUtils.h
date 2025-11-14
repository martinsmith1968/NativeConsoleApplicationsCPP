#pragma once

#include <list>
#include <string>

using namespace std;

namespace DNX::Utilities
{
    class ListUtils
    {
    public:
        static list<string> ToList(const char *array[]);
        static bool IsOneOf(const string& value, const list<string>& values, bool caseSensitive);
    };
}
