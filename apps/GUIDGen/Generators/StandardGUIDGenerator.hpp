#pragma once

#include "BaseGUIDGenerator.hpp"

class StandardGUIDGenerator : public BaseGUIDGenerator
{
public:
    string Generate() override;
};
