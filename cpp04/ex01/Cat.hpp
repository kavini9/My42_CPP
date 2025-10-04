/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:53:31 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/04 23:02:40 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat : public Animal {
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat&   operator=(const Cat& other);
		virtual ~Cat();
		
		void makeSound() const override;
};

#endif