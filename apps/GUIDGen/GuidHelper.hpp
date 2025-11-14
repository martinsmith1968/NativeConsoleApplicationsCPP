#pragma once

#include "Options.hpp"
//include "ooid/uuid.h"
#include "stduuid/uuid.h"
#include <string>

using namespace std;

enum GUIDGenerationModeType
{
    Standard,
    Kashmir
};

class GuidHelper
{
public:
#ifdef KL_UUID_H
    static string to_string(kashmir::uuid_t& uuid)
    {
        stringstream ss;
        ss << uuid;
        return ss.str();
    }

    static kashmir::uuid_t GenerateUUID(Options& options)
    {
        kashmir::uuid_t uuid;
        kashmir::system::DevRand devrandom;

        devrandom >> uuid;

        //auto ooid = new kashmir::uuid_t();

        return uuid;
    }
#endif

#ifdef STDUUID_H
    static string to_string(const uuids::uuid& uuid)
    {
        return uuids::to_string(uuid);
    }

    static uuids::uuid GenerateUUID()
    {
        std::random_device rd;
        auto seed_data = std::array<int, std::mt19937::state_size> {};
        std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
        std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
        std::mt19937 generator(seq);
        uuids::uuid_random_generator gen{generator};

        auto result = gen();

        return result;
    }
#endif
};
