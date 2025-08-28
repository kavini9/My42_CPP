/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:39:44 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/28 17:00:43 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*horde;

	horde = nullptr;
	if (N < 1)
	{
		std::cerr << SET_RED "A horde needs at least one zombie. N must be >= 1" RESET << std::endl;
		return (nullptr);
	}	
	try
	{
		horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].setName(name + "_" + std::to_string(i + 1));
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << SET_RED "bad_alloc caught: " << ba.what() << RESET << std::endl;
		return (nullptr);
	}
	return (horde);
}