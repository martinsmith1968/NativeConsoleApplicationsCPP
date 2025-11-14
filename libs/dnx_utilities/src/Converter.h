#pragma once

#include <string>
#include <map>
#include <list>

using namespace std;

namespace DNX::Utilities
{
    //--------------------------------------------------------------------------
    // Class: Converter
    //--------------------------------------------------------------------------
    class Converter
    {
    private:
        inline static map<string, bool> _default_bool_map
                {
                        {"true",  true},
                        {"false", false}
                };

        inline static list<string> _default_date_formats
                {
                        "%Y-%m-%d",
                        "%Y-%b-%d",
                        "%x",
                };

        inline static list<string> _default_time_formats
                {
                        "%H:%M",
                        "%X",
                };

    public:
        static bool IsChar(const string &value);

        static bool IsBool(const string &value);

        static bool IsBool(const string &value, bool caseSensitive);

        static bool IsBool(const string &value, const map<string, bool>& custom_bool_map);

        static bool IsBool(const string &value, const map<string, bool>& custom_bool_map, bool caseSensitive);

        static bool IsLong(const string &value);

        static bool IsInt(const string &value);

        static bool IsDouble(const string &value);

        static bool IsEnum(const string &value);

        static bool IsDate(const string &value);

        static bool IsDateTime(const string &value);

        static bool IsNumeric(const string &value)
        {
            return IsLong(value)
                || IsInt(value)
                || IsDouble(value);
        };

        static char ToChar(const string &value);

        static bool ToBool(const string &value);

        static bool ToBool(const string &value, bool caseSensitive);

        static bool ToBool(const string &value, map<string, bool> bool_map);

        static bool ToBool(const string &value, map<string, bool> bool_map, bool caseSensitive);

        static string ToText(bool value);

        static string ToText(bool value, const map<string, bool>& bool_map);

        static long ToLong(const string &value);

        static int ToInt(const string &value);

        static double ToDouble(const string &value);

        static bool ToDate(const string &value, tm *date);

        static bool ToDate(const string &value, tm *date, list<string> formats);

        static bool ToDateTime(const string &value, tm *datetime);

        static bool ToDateTime(const string &value, tm *datetime, list<string> date_formats, list<string> time_formats);
    };
}
