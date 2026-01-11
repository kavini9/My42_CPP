/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:20:24 by wweerasi          #+#    #+#             */
/*   Updated: 2026/01/08 16:14:23 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	typeCheckInt(const std::string& literal) {
	size_t pEnd;
	int val = std::stoi(literal, &pEnd, 10);
	if ()
}

bool	typeCheckFloat(const std::string& literal) {
	
}

bool	typeCheckDouble(const std::string& literal) {
	
}

void ScalarConverter::convert(const std::string& literal) {
	 bool isChar	= typeCheckChar(literal);
	 bool isInt		= typeCheckInt(literal);
	 bool isFloat	= typeCheckFloat(literal);
	 bool isDouble	= typeCheckDouble(literal);
}