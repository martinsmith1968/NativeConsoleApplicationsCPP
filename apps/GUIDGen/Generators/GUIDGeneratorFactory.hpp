#pragma once

#include "StandardGUIDGenerator.hpp"
#include "KashmirGUIDGenerator.hpp"

enum GUIDGeneratorType
{
    Standard = 0,
    Kashmir,
};

class GUIDGeneratorFactory
{
private:
    StandardGUIDGenerator _standard = StandardGUIDGenerator();
    KashmirGUIDGenerator  _kashmir  = KashmirGUIDGenerator();

public:
    BaseGUIDGenerator& Create(GUIDGeneratorType type)
    {
        switch (type)
        {
            case Kashmir:
                return _kashmir;

            case Standard:
            default:
                return _standard;
        }
    };
};
