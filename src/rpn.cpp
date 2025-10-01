#include "rpn.h"
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <cmath> // Не забудьте добавить этот include для std::sqrt!


double evaluate_rpn(const std::string& expression)
{
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2) throw std::invalid_argument("Not enough operands for operator " + token);
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
                if (token == "+") stack.push(a + b);
                else if (token == "-") stack.push(a - b);
                else if (token == "*") stack.push(a * b);
                else if (token == "/")
                {
                    if (b == 0) throw std::invalid_argument("Division by zero");
                    stack.push(a / b);
                }
        }
        else if (token == "sqrt")
        {
            if (stack.empty())
            {
                throw std::invalid_argument("Not enough operands for 'sqrt'");
            }
            double operand = stack.top();
            stack.pop();
            if (operand < 0)
            {
                throw std::invalid_argument("Square root of negative number");
            }
            stack.push(std::sqrt(operand));

        }
        else
        {
            try
            {
                stack.push(std::stod(token));
            }
            catch (const std::exception&) {
                throw std::invalid_argument("Invalid token: " + token);
            }
            }
        }
        if (stack.size() != 1) throw std::invalid_argument("Invalid expression");
        return stack.top();
    }
