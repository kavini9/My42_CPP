/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:02:57 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/02 22:07:13 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie*     zombie;

	zombie = nullptr;
	randomChump("Stacky");
	try
	{
		zombie = newZombie("Heapster");
	}
	catch (std::bad_alloc& ba)
	{
		std::cout << SET_RED "bad_alloc caught: " << ba.what() << RESET << std::endl;
		return (1);
	}
	zombie -> announce();
	delete zombie;
	return (0);
}