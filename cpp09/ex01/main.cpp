/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:35 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/22 17:24:35 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2) {
		std::cerr << SET_RED "Error: invalid no. of argument(s)." << std::endl
		<< "Usage: ./RPN <expression>" RESET << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		RPN expr;
		std::cout << expr.evaluate(av[1]) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << SET_RED "Error: " << e.what() << RESET << std::endl;
		return (EXIT_FAILURE);
	}
}