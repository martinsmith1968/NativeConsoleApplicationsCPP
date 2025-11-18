#pragma once

#pragma once

#include "BaseGUIDGenerator.hpp"

class KashmirGUIDGenerator : public BaseGUIDGenerator
{
public:
    string Generate() override;
};
