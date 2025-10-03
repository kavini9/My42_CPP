/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:35:36 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/02 22:48:27 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : virtual public ClapTrap {
	private:
		static unsigned int	_statHitPoints;
		static unsigned int	_statEnergyPoints;
		static unsigned int	_statAttackDamage;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap&   operator=(const FragTrap& other);
		~FragTrap();

		void 	highFivesGuys(void);

		static unsigned int	getStatHitPoints();
		static unsigned int	getStatEnergyPoints();
		static unsigned int	getStatAttackDamage();
};

#endif