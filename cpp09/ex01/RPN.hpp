/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:46 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/22 17:51:12 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <climits>
#include <stdexcept>

#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

class RPN {
	private:
		std::stack<int> _stack;
	
	public:
		RPN() = default;
		RPN(const RPN& other) = default;
		RPN& operator=(const RPN& other) = default;
		~RPN() = default;

		int evaluate(const std::string& expression);
};

#endif