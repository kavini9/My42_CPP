/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:40:36 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/09 22:37:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		Cure&    operator=(const Cure& other);
		~Cure();

		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif
