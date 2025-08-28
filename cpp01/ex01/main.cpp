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
	zombie = zombieHorde(nbZombie, "Zed");
	if (zombie)
	{
		for (int i = 0; i < nbZombie; i++)
			zombie[i].announce();
		delete[] zombie;
	}
	return (0);
}