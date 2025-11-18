#pragma once

#include <list>
#include <string>

using namespace std;

namespace DNX::Utilities
{
	class Strings
	{
	public:
        static bool IsNullOrEmpty(const string* str);
        static bool IsNullOrWhiteSpace(const string* str);
        static bool IsEmpty(const string& str);
        static bool IsEmptyOrWhiteSpace(const string& str);

        static string Trim(const string& str, char removeChar = ' ');
        static string LTrim(const string& str, char removeChar = ' ');
        static string RTrim(const string& str, char removeChar = ' ');

        static inline std::string ltrim(const std::string &value);
        static inline std::string rtrim(const std::string &value);
        static inline std::string trim(const std::string &value);

        static string Replace(const string& text, const string& search, const string& replace, bool caseSensitive = true);

        static string ToString(const char ch);

        static string ToLower(const string& text);
        static string ToUpper(const string& text);

        static string Left(const string& text, size_t length);
        static string Right(const string& text, size_t length);
        static bool Contains(const string& text, const string& search);
        static bool Contains(const string& text, const string& search, bool caseSensitive);

        static bool Equals(const string& str1, const string& str2, bool caseSensitive = false);

        static list<string> SplitText(const string& str, char splitChar = ',', char trimChar = '\0');
        static string JoinText(const list<string>& list, const string& delimiter);

        static bool StartsWith(const string& str, const string& prefix);
        static bool EndsWith(const string& str, const string& suffix);
        static bool StartsAndEndsWith(const string& str, const string& prefix, const string& suffix);
        static bool StartsAndEndsWith(const string& str, const string& prefixAndSuffix);

        static string EnsureStartsWith(const string& str, const string& prefix);
        static string EnsureEndsWith(const string& str, const string& suffix);
        static string EnsureStartsAndEndsWith(const string& str, const string& prefix, const string& suffix);
        static string EnsureStartsAndEndsWith(const string& str, const string& prefixAndSuffix);

        static string RemoveStartsWith(const string& str, const string& prefix);
        static string RemoveEndsWith(const string& str, const string& suffix);
        static string RemoveStartsAndEndsWith(const string& str, const string& prefix, const string& suffix);
        static string RemoveStartsAndEndsWith(const string& str, const string& prefixAndSuffix);

        static string Before(const string& text, const string& marker);
        static string After(const string& text, const string& marker);
        static string BeforeLast(const string& text, const string& marker);
        static string AfterLast(const string& text, const string& marker);

        static string Between(const string& text, const string& firstMarker, const string& secondMarker);
        static string Between(const string& text, const string& firstAndSecondMarker);
        static string BetweenInner(const string& text, const string& firstAndSecondMarker);
        static string BetweenInner(const string& text, const string& firstMarker, const string& secondMarker);
        static string BetweenOuter(const string& text, const string& firstAndSecondMarker);
        static string BetweenOuter(const string& text, const string& firstMarker, const string& secondMarker);
	};
}
