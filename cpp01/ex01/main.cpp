/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:02:57 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/01 16:38:03 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie*     zombie;
	int			nbZombie;
	
	nbZombie = 0;
	zombie = zombieHorde(nbZombie, "Zed");
	if (zombie)
	{
		for (int i = 0; i < nbZombie; i++)
			zombie[i].announce();
		delete[] zombie;
	}
	else
		return (1);
	return (0);
}

/*test cases*/
/*
nbZombie = 1000000000;
nbZombie = 0;
*/