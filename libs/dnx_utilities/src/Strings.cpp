#include "Strings.h"
#include <sstream>
#include <algorithm>

using namespace DNX::Utilities;


bool Strings::IsNullOrEmpty(const std::string* str)
{
    return str == nullptr || IsEmpty(*str);
}

bool Strings::IsNullOrWhiteSpace(const std::string* str)
{
    return str == nullptr || IsEmptyOrWhiteSpace(*str);
}

bool Strings::IsEmpty(const std::string& str)
{
    return str.length() == 0;
}

bool Strings::IsEmptyOrWhiteSpace(const std::string& str)
{
    if (IsEmpty(str))
        return true;

    for (auto ch : str)
    {
        if (!isspace(ch) && !isblank(ch) && !iscntrl(ch))
            return false;
    }

    return true;
}

string Strings::Trim(const string& str, const char removeChar)
{
    return LTrim(RTrim(str, removeChar), removeChar);
}

string Strings::LTrim(const string& str, const char removeChar)
{
    const auto first = str.find_first_not_of(removeChar);
    if (first == string::npos)
    {
        return "";
    }

    return str.substr(first, string::npos);
}

string Strings::RTrim(const string& str, const char removeChar)
{
    const auto last = str.find_last_not_of(removeChar);
    if (last == string::npos)
    {
        return "";
    }

    return str.substr(0, last + 1);
}

// trim from start
// https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
inline std::string Strings::ltrim(const std::string &value) {
    std::string str = value;
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
    return str;
}

// trim from end (in place)
// https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
inline std::string Strings::rtrim(const std::string &value) {
    std::string str = value;
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), str.end());
    return str;
}

// trim from both ends (in place)
// https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
inline std::string Strings::trim(const std::string &value) {
    return ltrim(rtrim(value));
}

string Strings::Replace(const string& text, const string& search, const string& replace, bool caseSensitive)
{
    size_t pos = 0;

    string returnText = text;

    if (search.length() > 0)
    {
        auto textCI = caseSensitive ? search : Strings::ToLower(returnText);
        auto searchCI = caseSensitive ? search : Strings::ToLower(search);

        while ((pos = textCI.find(searchCI, pos)) != string::npos)
        {
            returnText.replace(pos, search.length(), replace);
            pos += replace.length();

            textCI = caseSensitive ? search : Strings::ToLower(returnText);
        }
    }

    return returnText;
}

string Strings::ToString(const char ch)
{
    return string(1, ch);
}

string Strings::ToLower(const string& text)
{
    string result = text;

    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return result;
}

string Strings::ToUpper(const string& text)
{
    string result = text;

    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::toupper(c); });

    return result;
}

string Strings::Left(const string& text, const size_t length)
{
    const auto text_length = text.length() > 0 && text.length() > length
        ? length
        : text.length();

    return text.substr(0, text_length);
}

string Strings::Right(const string& text, const size_t length)
{
    const auto text_length = text.length() > 0 && text.length() > length
        ? length
        : text.length();

    return text.substr(text.length() - text_length, string::npos);
}

bool Strings::Contains(const string& text, const string& search)
{
    const auto pos = search.length() > 0
        ? text.find(search)
        : string::npos;

    return pos != string::npos;
}

/*
string Strings::BoolToString(const bool value, const string& trueValue, const string& falseValue)
{
    return value
        ? trueValue
        : falseValue;
}
 */

bool Strings::Equals(const string& str1, const string& str2, bool caseSensitive)
{
    return (str1.size() == str2.size())
        && std::equal(str1.begin(), str1.end(), str2.begin(),
            [caseSensitive](const char& c1, const char& c2)
            {
                return (c1 == c2 || (!caseSensitive && std::toupper(c1) == std::toupper(c2)));
            }
    );
}

list<string> Strings::SplitText(const string& str, const char splitChar, const char trimChar)
{
    stringstream ss(str);

    list<string> list;

    while (ss.good())
    {
        string piece;
        getline(ss, piece, splitChar);

        if (trimChar != '\0')
        {
            piece = Trim(piece, trimChar);
        }

        if (!piece.empty())
        {
            list.push_back(piece);
        }
    }

    return list;
}

string Strings::JoinText(const list<string>& list, const string& delimiter)
{
    ostringstream ss;

    for (auto iter = list.begin(); iter != list.end(); ++iter)
    {
        if (iter != list.begin())
        {
            ss << delimiter;
        }

        ss << *iter;
    }

    return ss.str();
}

bool Strings::StartsWith(const string& str, const string& prefix)
{
    if (str.length() < prefix.length() || prefix.length() < 1)
        return false;

    return Left(str, prefix.length()) == prefix;
}

bool Strings::EndsWith(const string& str, const string& suffix)
{
    if (str.length() < suffix.length() || suffix.length() < 1)
        return false;

    return Right(str, suffix.length()) == suffix;
}

bool Strings::StartsAndEndsWith(const string& str, const string& prefix, const string& suffix)
{
    return StartsWith(str, prefix) && EndsWith(str, suffix);
}

bool Strings::StartsAndEndsWith(const string& str, const string& prefixAndSuffix)
{
    return StartsAndEndsWith(str, prefixAndSuffix, prefixAndSuffix);
}

string Strings::EnsureStartsWith(const string& str, const string& prefix)
{
    return StartsWith(str, prefix)
        ? str
        : prefix + str;
}

string Strings::EnsureEndsWith(const string& str, const string& suffix)
{
    return EndsWith(str, suffix)
        ? str
        : str + suffix;
}

string Strings::EnsureStartsAndEndsWith(const string& str, const string& prefixAndSuffix)
{
    return EnsureStartsAndEndsWith(str, prefixAndSuffix, prefixAndSuffix);
}

string Strings::EnsureStartsAndEndsWith(const string& str, const string& prefix, const string& suffix)
{
    return EnsureStartsWith(EnsureEndsWith(str, suffix), prefix);
}

string Strings::RemoveStartsWith(const string& str, const string& prefix)
{
    string result = str;
    while (StartsWith(result, prefix))
    {
        result = result == prefix
            ? ""
            : result.substr(prefix.length(), string::npos);
    }

    return result;
}

string Strings::RemoveEndsWith(const string& str, const string& suffix)
{
    string result = str;
    while (EndsWith(result, suffix))
    {
        result = result == suffix
            ? ""
            : result.substr(0, result.length() - suffix.length());
    }

    return result;
}

string Strings::RemoveStartsAndEndsWith(const string& str, const string& prefixAndSuffix)
{
    return RemoveStartsAndEndsWith(str, prefixAndSuffix, prefixAndSuffix);
}

string Strings::RemoveStartsAndEndsWith(const string& str, const string& prefix, const string& suffix)
{
    return RemoveStartsWith(RemoveEndsWith(str, suffix), prefix);
}

string Strings::Before(const string& text, const string& marker)
{
    const auto pos = marker.length() > 0
        ? text.find(marker)
        : string::npos;

    return pos == string::npos
        ? ""
        : text.substr(0, pos);
}

string Strings::After(const string& text, const string& marker)
{
    const auto pos = marker.length() > 0
        ? text.find(marker)
        : string::npos;

    return pos == string::npos
        ? ""
        : text.substr(pos + marker.length());
}

string Strings::BeforeLast(const string& text, const string& marker)
{
    const auto pos = marker.length() > 0
        ? text.rfind(marker)
        : string::npos;

    return pos == string::npos
        ? ""
        : text.substr(0, pos);
}

string Strings::AfterLast(const string& text, const string& marker)
{
    const auto pos = marker.length() > 0
        ? text.rfind(marker)
        : string::npos;

    return pos == string::npos
        ? ""
        : text.substr(pos + marker.length());
}

string Strings::Between(const string& text, const string& firstMarker, const string& secondMarker)
{
    return Before(After(text, firstMarker), secondMarker);
}

string Strings::Between(const string& text, const string& firstAndSecondMarker)
{
    return Between(text, firstAndSecondMarker, firstAndSecondMarker);
}

string Strings::BetweenInner(const string& text, const string& firstMarker, const string& secondMarker)
{
    return Before(AfterLast(text, firstMarker), secondMarker);
}

string Strings::BetweenOuter(const string& text, const string& firstMarker, const string& secondMarker)
{
    return BeforeLast(After(text, firstMarker), secondMarker);
}

string Strings::BetweenOuter(const string& text, const string& firstAndSecondMarker)
{
    return BetweenOuter(text, firstAndSecondMarker, firstAndSecondMarker);
}
