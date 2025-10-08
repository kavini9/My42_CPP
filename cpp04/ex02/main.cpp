/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:14:01 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/08 18:50:07 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define SET_B_YLW	"\033[1;33m"
#define RESET		"\033[0m"
#define ELE_COUNT		10

int main()
{
	// {
	// 	Animal a;
	// }
	{
		std::cout << SET_B_YLW "Destructor Chain Validation" RESET  << std::endl;
		const Animal* i = nullptr;
		const Animal* j = nullptr;
		try {
			j = new Dog();
			i = new Cat();
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		std::cout << SET_B_YLW "Destructor Chain Validation" RESET  << std::endl;
		const Dog i;
		const Cat j;
		std::cout << std::endl;
		const Animal& i_= i;
		const Animal& j_= j;
		i_.makeSound();
		// i_.Animal::makeSound();
		j_.makeSound();
		// j_.Animal::makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// throw std::bad_alloc();