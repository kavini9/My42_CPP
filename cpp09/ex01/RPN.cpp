/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:43 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/19 22:39:44 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::evaluate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.length() != 1)
            throw std::runtime_error("erroneous expression.");
        if (std::isdigit(token[0]))
            _stack.push(token[0] - '0');
        else {
            if (_stack.size() < 2)
                throw std::runtime_error("too few operands.");
            long rhs = _stack.top(); _stack.pop();
            long lhs = _stack.top(); _stack.pop();
            long res;
            switch (token[0]) {
                case '+': res = lhs + rhs; break;
                case '-': res = lhs - rhs; break;
                case '*': res = lhs * rhs; break;
                case '/': (rhs != 0)? res = lhs / rhs : throw std::runtime_error("division by zero."); break;
                default: throw std::runtime_error("erroneous expression.");
            }
            if (res < INT_MIN) throw std::runtime_error("integer underflow.");
            if (res > INT_MAX) throw std::runtime_error("integer overflow.");
            _stack.push(res);
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("too few operators.");
    return _stack.top();
}