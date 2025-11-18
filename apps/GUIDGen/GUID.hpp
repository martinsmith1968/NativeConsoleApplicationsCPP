#pragma once

#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
#include <array>
#include <string_view>
#include <iterator>
#include <random>
#include <memory>
#include <functional>
#include <type_traits>
#include <optional>
#include <chrono>
#include <numeric>
#include <atomic>
#include <algorithm>
#include <iterator>

using namespace std;

class MyGUID
{
private:
    byte _bytes[16] { };

public:
    explicit MyGUID(const byte bytes[16])
    {
        copy(bytes, bytes + 16, begin(_bytes));
    }

    //string ToString() const;
};
