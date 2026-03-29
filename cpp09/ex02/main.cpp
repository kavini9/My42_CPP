/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:51 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/29 06:45:01 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << SET_RED "Error: invalid no. of argument(s)." << std::endl
		<< "Usage: ./PmergeMe <non-negative integer sequence>" RESET << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		PmergeMe app;
		app.run(&av[1]);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return (EXIT_SUCCESS);
}