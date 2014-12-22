#include <iostream>
#include <string>
#include <stack>
#include <cmath>

class rpn {
protected:
    typedef std::stack<char> sign_stack_t;

    static short get_priority(const char sign);

    static const char *get_expression(sign_stack_t &stack);

public:
    static std::string convert(std::string string);

    static double calculate(std::string input);
};