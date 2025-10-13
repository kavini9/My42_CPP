/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:14:01 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/13 21:46:55 by wweerasi         ###   ########.fr       */
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
	// 	Animal a; // Attempting to instantiate an abstract class (will not compile)
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
		std::cout << SET_B_YLW "Dynamic Dispatch of a Pure Virtual Function" RESET  << std::endl;
		const Dog i;
		const Cat j;
		std::cout << std::endl;
		const Animal& i_= i;
		const Animal& j_= j;
		i_.makeSound();
		// i_.Animal::makeSound(); //works when abstract base class has definition for the pure virtual function
		j_.makeSound();
		// j_.Animal::makeSound(); //works when abstract base class has definition for the pure virtual function
		std::cout << std::endl; 
	}
	std::cout << std::endl;
}

// throw std::bad_alloc();