/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:02:57 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/27 21:47:45 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie*     zombie;
	int			nbZombie;
	
	nbZombie = 5;
	try
	{
		zombie = zombieHorde(nbZombie, "Chap");
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