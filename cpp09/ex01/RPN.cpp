/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:43 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/31 21:48:10 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::evaluate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() != 1)
            throw std::runtime_error("erroneous expression.");
        char c = token[0];
        if (std::isdigit(c))
            _stack.push(c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (_stack.size() < 2)
                throw std::runtime_error("too few operands.");
            long rhs = _stack.top(); _stack.pop();
            long lhs = _stack.top(); _stack.pop();
            long res;
            switch (c) {
                case '+': res = lhs + rhs; break;
                case '-': res = lhs - rhs; break;
                case '*': res = lhs * rhs; break;
                case '/': (rhs != 0)? res = lhs / rhs : throw std::runtime_error("division by zero."); break;
            }
            if (res < INT_MIN) throw std::runtime_error("integer underflow.");
            if (res > INT_MAX) throw std::runtime_error("integer overflow.");
            _stack.push(res);
        }
        else
            throw std::runtime_error("erroneous expression.");
    }
    if (_stack.empty())
        throw std::runtime_error("empty expression.");
    if (_stack.size() != 1)
        throw std::runtime_error("too few operators.");
    return _stack.top();
}