/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:54:59 by wweerasi          #+#    #+#             */
/*   Updated: 2026/01/20 21:47:12 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
	{
		std::cout << "Usage:./scalar_converter <parameter>" << std::endl;
		return (EXIT_FAILURE);
	}
    try {
        ScalarConverter::convert(argv[1]);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}