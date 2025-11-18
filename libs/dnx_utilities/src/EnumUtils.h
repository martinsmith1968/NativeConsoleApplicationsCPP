#pragma once

#include <list>
#include <map>
#include <string>
#include "Maps.h"

using namespace std;

namespace DNX::Utilities
{
    // TODO: Introduce text categories by value of T (MetaData ?)
    // TODO: Friendly constructor
    template<class T = int>
    class TextEnum
    {
        map<T, string> _map;

    protected:
        void SetText(const T value, const string text)
        {
            _map[value] = text;
        }

    public:
        string GetText(const T value) const
        {
            return Maps::FindFirstByKey(value, _map);
        }

        T GetValue(const string text) const
        {
            return Maps::FindByValue(text, _map);
        }

        [[nodiscard]] list<string> GetAllText() const
        {
            return Maps::ValuesToList(_map);
        }

        list<T> GetAllValues() const
        {
            return Maps::KeysToList(_map);
        }
    };
}
