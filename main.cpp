#include <iostream>
#include "rpn.h"

int main() {
    std::string input;

    try {
        std::getline(std::cin, input, '\n');
        std::string rpn = rpn::convert(input);
        std::cout << rpn << std::endl;
        double result = rpn::calculate(rpn);
        std::cout << result;
        return 0;
    } catch (const std::runtime_error *&err) {
        std::cerr << err->what();
        return 1;
    }
}