/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:29:08 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/28 22:10:07 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		_weapon;
	
	public:
		//HumanA();
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		void	attack(std::string name, Weapon weapon);
};

#endif