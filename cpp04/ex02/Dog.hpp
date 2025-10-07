/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:53:42 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/06 19:06:33 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
	private:
		Brain* _brain;
		
	public:
		Dog();
		Dog(const Dog& other);
		Dog&   operator=(const Dog& other);
		virtual ~Dog();
		
		void makeSound() const override;

		Brain* getBrain() const;
};

#endif