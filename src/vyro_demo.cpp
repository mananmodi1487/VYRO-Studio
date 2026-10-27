#include <iostream>
#include <string_view>
#include "vyro/version.h"

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string_view(argv[1]) == "--version-check") {
        constexpr std::string_view v = vyro::version();
        if (v.empty()) {
            std::cerr << "FAIL: version string is empty\n";
            return 1;
        }
        std::cout << "VYRO Studio " << v << '\n';
        return 0;
    }
    std::cout << "VYRO Studio " << vyro::version() << '\n';
    return 0;
}