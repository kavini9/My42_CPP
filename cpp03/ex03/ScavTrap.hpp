/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:06:44 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/03 19:33:33 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : virtual public ClapTrap {
	private:
		static unsigned int	_statHitPoints;
		static unsigned int	_statEnergyPoints;
		static unsigned int	_statAttackDamage;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap&   operator=(const ScavTrap& other);
		~ScavTrap();

		void	attack(const std::string& target) override;
		void	guardGate();

		static unsigned int	getStatHitPoints();
		static unsigned int	getStatEnergyPoints();
		static unsigned int	getStatAttackDamage();
};

#endif