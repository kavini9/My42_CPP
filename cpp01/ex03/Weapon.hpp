/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:10:21 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/29 19:22:27 by wweerasi         ###   ########.fr       */
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
	
		const std::string&	getType() const;
		void				setType(std::string type);
};

#endif