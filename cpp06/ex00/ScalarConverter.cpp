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

bool isChar(const std::string& lit, double& dbl) {
	if (lit.length() != 1 || !std::isprint(lit.front()))
		return false;
	dbl = static_cast<double> (lit.front());
	return true;
}

bool isInt(const std::string& lit, double& dbl) {
	errno = 0;
	char* pEnd;
	long val = std::strtol(lit.c_str(), &pEnd, 10);
	dbl = static_cast<double> (val);
	return pEnd != lit.c_str() && *pEnd == '\0' && errno != ERANGE 
	&& val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

bool isFloat(const std::string& lit, double& dbl) {
	errno = 0;
	char* pEnd; 
	float val = std::strtof(lit.c_str(), &pEnd);
	dbl = static_cast<double> (val);
	return (lit.find('.') != lit.npos || !std::isfinite(dbl)) && pEnd != lit.c_str() && *pEnd == 'f'
		&& *(pEnd + 1) == '\0';// && errno != ERANGE; 
}

bool isDouble(const std::string& lit, double& dbl) {
	errno = 0;
	char* pEnd;
	dbl = std::strtod(lit.c_str(), &pEnd);
	return pEnd != lit.c_str()
		&& *pEnd == '\0';// && errno != ERANGE;//can errno cause problems with inf
		//(lit.find('.') != lit.npos || !std::isfinite(dbl)) && 
}

std::string formatFrac(double val, bool decFlag)
{
	std::ostringstream ss;
    decFlag
        ? (ss << std::fixed << std::setprecision(1))
        : (ss << std::setprecision(std::numeric_limits<double>::max_digits10));
    ss << val;
    return ss.str();
}

void ScalarConverter::convert(const std::string& lit) {
	double	d ;
	bool	decFlag = false;
	if (!lit.empty() && (isChar(lit, d) || isInt(lit, d) ||isFloat(lit, d) || isDouble(lit, d))) {
		char	c = static_cast<char> (d);
		int		i = static_cast<int> (d);
		float	f = static_cast<float> (d);

        if (static_cast<double>(c) == d) {
            if (std::isprint(c))
                std::cout << "char:	'" << c << "'" << std::endl;
            else
                std::cout << "char:	Non displayable" << std::endl;
        } 
		else
            std::cout << "char:	impossible" << std::endl;
        if (static_cast<double>(i) == d) {
            std::cout << "int:	" << i << std::endl;
			decFlag = true;
		}
        else
            std::cout << "int:	impossible" << std::endl;
        if (static_cast<double>(f) == d || !std::isfinite(f))
            std::cout << "float:	" << formatFrac(f, decFlag) << "f" << std::endl;
        else
            std::cout << "float:	impossible\n";
        std::cout << "double:	" << formatFrac(d, decFlag) << std::endl;
    } else
        std::cout << "Invalid input" << std::endl;
}
//inf and nan doesnt work.
//big numbers are printed in scientific notation

//./scalar_converter 1e39