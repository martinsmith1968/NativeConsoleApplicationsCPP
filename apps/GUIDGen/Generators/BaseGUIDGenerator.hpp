#pragma once

#include <string>

using namespace std;

class BaseGUIDGenerator
{
public:
    virtual string Generate() = 0;
    virtual string Empty() = 0;
};
