#include "Maps.h"
#include "Comparator.h"

using namespace DNX::Utilities;

template<typename K, typename V>
list<K> Maps::KeysToList(map<K, V> items)
{
    list<K> result;

    for (auto item: items)
        result.push_back(item.first);

    return result;
}

template<typename T, typename V>
vector<T> Maps::KeysToVector(map<T, V> items)
{
    vector<T> result;

    for (auto item: items)
        result.push_back(item.first);

    return result;
}

template<typename T, typename V>
list<V> Maps::ValuesToList(map<T, V> items)
{
    list<V> result;

    for (auto item: items)
        result.push_back(item.second);

    return result;
}

template<typename T, typename V>
vector<V> Maps::ValuesToVector(map<T, V> items)
{
    vector<V> result;

    for (auto item: items)
        result.push_back(item.second);

    return result;
}

template<typename K, typename V>
V Maps::FindFirstByKey(K key, map<K, V> items)
{
    return Maps::FindFirstByKey(key, items, Comparator::DefaultComparator);
}

template<typename K, typename V>
V Maps::FindFirstByKey(K key, map<K, V> items, bool (*comparator)(K, K))
{
    V result;

    for (auto item: items)
    {
        if (comparator(item.first, key))
        {
            result = item.second;
            break;
        }
    }

    return result;
}

template<typename K, typename V>
K Maps::FindByValue(V value, map<K, V> items)
{
    return Maps::FindByValue(value, items, Comparator::DefaultComparator);
}

template<typename T, typename V>
T Maps::FindByValue(V value, map<T, V> items, bool (*comparator)(V, V))
{
    T result;

    for (auto item: items)
    {
        if (comparator(item.second, value))
        {
            result = item.first;
            break;
        }
    }

    return result;
}
