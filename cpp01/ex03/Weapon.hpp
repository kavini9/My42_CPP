/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:10:21 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/28 21:52:04 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string  _type;
	
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
	
		const std::string&	getType();
		void				setType(std::string& newtype);
};

#endif