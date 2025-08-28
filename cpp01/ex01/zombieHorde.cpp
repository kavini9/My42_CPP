/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:39:44 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/27 22:48:23 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
	{
		std::cerr << "A horde needs at least one zombie. N must be >= 1" << std::endl;
		return (nullptr);
	}	
	try
	{
		Zombie *horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].setName(name + "_" + std::to_string(i + 1));
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		return (nullptr);
	}
	return (horde);
}