#include "Converter.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include "Maps.h"
#include "Strings.h"
#include "ListUtils.h"

using namespace DNX::Utilities;

bool Converter::IsChar(const string& value)
{
    return !value.empty() && value.length() == 1;
}

bool Converter::IsBool(const string& value)
{
    return IsBool(value, Converter::_default_bool_map, false);
}

bool Converter::IsBool(const string& value, bool caseSensitive)
{
    return IsBool(value, Converter::_default_bool_map, caseSensitive);
}

bool Converter::IsBool(const string& value, const map<string, bool>& custom_bool_map)
{
    return IsBool(value, custom_bool_map, false);
}

bool Converter::IsBool(const string& value, const map<string, bool>& custom_bool_map, bool caseSensitive)
{
    const auto keys = Maps::KeysToList(custom_bool_map);

    return ListUtils::IsOneOf(value, keys, caseSensitive);
}

bool Converter::IsLong(const string& value)
{
    if (value.empty())
        return false;

    auto trimmedValue = Strings::Trim(value);
    if (value.empty() || !isdigit(trimmedValue[0]))
        return false;

    char* p = 0;
    auto parsed = strtol(value.c_str(), &p, 10);

    return (p != value.c_str());
}

bool Converter::IsInt(const string& value)
{
    if (!IsLong(value))
        return false;

    auto parsed = ToLong(value);

    return parsed <= INT_MAX;
}

bool Converter::IsDouble(const string& value)
{
    if (value.empty() || ((!isdigit(value[0])) && (value[0] != '-') && (value[0] != '+')))
        return false;

    char* p;
    auto parsed = strtod(value.c_str(), &p);

    return (p != value.c_str());
}

bool Converter::IsEnum(const string& value)
{
    return !value.empty() || IsInt(value);
}

bool Converter::IsDate(const string& value)
{
    tm temp{ };
    return ToDate(value, &temp);
}

bool Converter::IsDateTime(const string& value)
{
    tm temp { };
    return ToDateTime(value, &temp);
}

char Converter::ToChar(const string& value)
{
    return value.at(0);
}

bool Converter::ToBool(const string& value)
{
    return ToBool(value, _default_bool_map);
}

bool Converter::ToBool(const string& value, bool caseSensitive)
{
    return IsBool(value, _default_bool_map, caseSensitive);
}

bool Converter::ToBool(const string& value, const map<string, bool> bool_map)
{
    return IsBool(value, bool_map, true);
}

bool Converter::ToBool(const string& value, const map<string, bool> bool_map, bool caseSensitive)
{
    const auto keys = Maps::KeysToList(bool_map);

    return ListUtils::IsOneOf(value, keys, caseSensitive);
}

string Converter::ToText(bool value)
{
    return ToText(value, _default_bool_map);
}

string Converter::ToText(bool value, const map<string, bool>& bool_map)
{
    auto text = Maps::FindByValue(value, bool_map);

    return text;
}

long Converter::ToLong(const string& value)
{
    if (!IsLong(value))
        return 0;

    return strtol(value.c_str(), nullptr, 10);
}

int Converter::ToInt(const string& value)
{
    return IsInt(value) ? stoi(value) : 0;
}

double Converter::ToDouble(const string& value)
{
    return stod(value);
}

// From : https://stackoverflow.com/questions/321849/strptime-equivalent-on-windows
extern "C" char* strptime(const char* s, const char* f, struct tm* tm)
{
    // Isn't the C++ standard lib nice? std::get_time is defined such that its
    // format parameters are the exact same as strptime. Of course, we have to
    // create a string stream first, and imbue it with the current C locale, and
    // we also have to make sure we return the right things if it fails, or
    // if it succeeds, but this is still far simpler an implementation than any
    // of the versions in any of the C standard libraries.
    std::istringstream input(s);
    input.imbue(std::locale(setlocale(LC_ALL, nullptr)));
    input >> std::get_time(tm, f);
    if (input.fail())
    {
        return nullptr;
    }

    return const_cast<char*>(s + input.tellg());
}

bool Converter::ToDate(const string& value, tm* date)
{
    return Converter::ToDate(value, date, _default_date_formats);
}

bool Converter::ToDate(const string& value, tm* date, list<string> formats)
{
    tm parsed { };

    for (auto date_format = formats.begin(); date_format != formats.end(); ++date_format)
    {
        if (strptime(value.c_str(), date_format->c_str(), &parsed) != nullptr)
        {
            *date = parsed;

            return true;
        }
    }

    return false;
}

bool Converter::ToDateTime(const string& value, tm* datetime)
{
    return ToDateTime(value, datetime, _default_date_formats, _default_time_formats);
}

bool Converter::ToDateTime(const string& value, tm* datetime, list<string> date_formats, list<string> time_formats)
{
    tm parsed { };

    for (auto date_format = date_formats.begin(); date_format != date_formats.end(); ++date_format)
    {
        for (auto time_format = time_formats.begin(); time_format != time_formats.end(); ++time_format)
        {
            auto format = *date_format + " " + *time_format;

            if (strptime(value.c_str(), format.c_str(), &parsed) != nullptr)
            {
                *datetime = parsed;

                return true;
            }
        }
    }

    return false;
}
