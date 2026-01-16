/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:20:24 by wweerasi          #+#    #+#             */
/*   Updated: 2026/01/16 23:03:51 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isChar(const std::string& lit, double& dbl) {
	if (lit.length() != 1 || !std::isprint(lit.front()))
		return false;
	dbl = static_cast<double> (lit.front());
	return true;
}

bool	isInt(const std::string& lit, double& dbl) {
	char* pEnd;
	long val = std::strtol(lit.c_str(), &pEnd, 10);
	dbl = static_cast<double> (val);
	return pEnd != lit.c_str() && *pEnd == '\0' && errno != ERANGE &&
		val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

bool	isFloat(const std::string& lit, double& dbl) {
	char* pEnd;
	long val = std::strtof(lit.c_str(), &pEnd);
	dbl = static_cast<double> (val);
	return	pEnd != lit.c_str() && *pEnd == 'f' &&
		*(pEnd + 1) == '\0' && errno != ERANGE; 
}

bool	isDouble(const std::string& lit, double& dbl) {
	char* pEnd;
	long val = std::strtod(lit.c_str(), &pEnd);
	return pEnd != lit.c_str() && *pEnd == '\0' && errno != ERANGE;
}

void ScalarConverter::convert(const std::string& lit) {
	double dbl ;
	if (!lit.empty() && (isChar(lit, dbl) || isInt(lit, dbl) ||isFloat(lit, dbl) || isDouble(lit, dbl))) {
		
	}
	else {
		
	}
}