#include "rpn.h"

short rpn::get_priority(const char sign) {
    switch (sign) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

const char *rpn::get_expression(sign_stack_t &stack) {
    size_t size = stack.size() * 2;
    char *result = new char[size];
    char sign;
    for (size_t i = 0; i < size; ++i) {
        sign = stack.top();

        if (sign == '(') {
            stack.pop();

            return result;
        }
        result[i] = ' ';
        i++;
        result[i] = sign;
        stack.pop();
    }
    return result;
}


std::string rpn::convert(std::string input) {
    std::string expression("");
    sign_stack_t stack;

    for (auto sign : input) {
        switch (sign) {
            case ' ':
            case '\n':
            case '\r':
            case '\t':
                continue;
            case '(':
                stack.push(sign);
                break;
            case ')':
                expression += get_expression(stack);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (stack.empty() || get_priority(sign) > get_priority(stack.top())) {
                    stack.push(sign);
                } else {
                    expression += ' ';
                    expression += stack.top();
                    stack.pop();
                    stack.push(sign);
                }
                expression += ' ';
                break;
            default:
                expression += sign;
                break;
        }
    }

    return expression + get_expression(stack);
}

double rpn::calculate(std::string rpn) {
    double num, n1, n2, res;
    char *temp = new char[rpn.size()];
    strcpy(temp, rpn.c_str());
    std::stack<double> nums;
    for (char *token = strtok(temp, " "); token != NULL; token = strtok(NULL, " ")) {
        num = atof(token);
        if (num != 0 || token[0] == 0) {
            nums.push((double) num);
        } else {
            n2 = nums.top();
            nums.pop();
            n1 = nums.top();
            nums.pop();
            switch (token[0]) {
                case '+':
                    res = n1 + n2;
                    break;
                case '-':
                    res = n1 - n2;
                    break;
                case '*':
                    res = n1 * n2;
                    break;
                case '/':
                case ':':
                    res = n1 / n2;
                    break;
                case '^':
                    res = pow((double) n1, (double) n2);
                    break;
            }
            nums.push(res);
        }
    }
    return nums.top();
}