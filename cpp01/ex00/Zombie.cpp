/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:13:37 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/20 21:23:13 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie(){}

void    Zombie::announce(void)
{
    std::cout << name << "BraiiiiiiinnnzzzZ..." << std::endl;
}