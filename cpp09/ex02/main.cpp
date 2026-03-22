/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:51 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/22 18:26:23 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << SET_RED "Error: invalid no. of argument(s)." << std::endl
		<< "Usage: ./PmergeMe <positive integer sequence>" RESET << std::endl;
		return (EXIT_FAILURE);
	}
    
    
}