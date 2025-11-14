#include <iostream>
#include "src/Strings.h"

using namespace std;
using namespace DNX::Utilities;

int main() {
    auto xx = Strings::LTrim("...BannerText...", '.');

    std::cout << xx << std::endl;
    return 0;
}
