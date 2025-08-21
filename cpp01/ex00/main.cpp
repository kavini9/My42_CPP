/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:02:57 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/21 22:49:19 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie*     zombie;
	
	randomChump("Stacky");
	try
	{
		zombie = newZombie("Heapster");
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		return EXIT_FAILURE;
	}
	zombie -> announce();
	delete zombie;
	return EXIT_SUCCESS;
}