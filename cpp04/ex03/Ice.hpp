/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:43 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/09 22:45:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& other);
		Ice&    operator=(const Ice& other);
		~Ice();

		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif