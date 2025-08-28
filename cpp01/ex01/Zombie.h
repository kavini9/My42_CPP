/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:31:14 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/28 16:50:37 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

#endif