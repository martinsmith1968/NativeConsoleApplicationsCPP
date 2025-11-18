#include "CLI/CLI11.hpp"
#include "stduuid/uuid.h"
#include "Options.hpp"
#include "GUID.hpp"
#include <filesystem>

#include "boost/dll/runtime_symbol_info.hpp"

using namespace filesystem;

int main(int argc, char* argv[])
{
    Options options;

    CLI11_PARSE(options.Application, argc, argv);

    if (options.OutputHeader)
    {
        cout << APP_HEADER << std::endl;
        cout << APP_COPYRIGHT << std::endl;
        cout << std::endl;
    }

    //auto factory = GUIDGeneratorFactory();
    //auto generator = factory.Create(options.GenerationMode)


    auto xx = GuidHelper::GenerateUUID();
    auto yy = xx.as_bytes();
    // TODO:  auto gg = MyGUID(yy.);


    // Generate as many as requested
    if (options.Count > 0)
    {
        for (auto index = 1; index <= options.Count; ++index)
        {
            auto uuid = GuidHelper::to_string(GuidHelper::GenerateUUID());

            auto output = options.FormatGUID(uuid, index);

            if (index > 1)
                std::cout << options.Delimiter;

            std::cout << output;
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
