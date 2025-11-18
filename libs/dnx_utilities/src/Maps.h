#pragma once

#include <map>
#include <list>
#include <vector>

using namespace std;

namespace DNX::Utilities
{
    class Maps
    {
    public:
        template<typename K, typename V>
        static list<K> KeysToList(map<K, V> items);

        template<typename T, typename V>
        static vector<T> KeysToVector(map<T, V> items);

        template<typename T, typename V>
        static list<V> ValuesToList(map<T, V> items);

        template<typename T, typename V>
        static vector<V> ValuesToVector(map<T, V> items);

        template<typename K, typename V>
        static V FindFirstByKey(K key, map<K, V> items);

        template<typename K, typename V>
        static V FindFirstByKey(K key, map<K, V> items, bool (*comparator)(K, K));

        template<typename K, typename V>
        static K FindByValue(V value, map<K, V> items);

        template<typename T, typename V>
        static T FindByValue(V value, map<T, V> items, bool (*comparator)(V, V));
    };
}
