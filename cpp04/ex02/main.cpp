/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:14:01 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/07 23:04:54 by wweerasi         ###   ########.fr       */
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
		//const Dog* iptr = &i;

		const Animal& i_= i;
		i_.makeSound();
		i_.Animal::makeSound();
		std::cout << std::endl;
	}
	// {
	// 	std::cout << SET_B_YLW "Animal Inheritance" RESET  << std::endl;
	// 	const Animal* meta = nullptr;
	// 	const Animal* i = nullptr;
	// 	const Animal* j = nullptr;
	// 	try {
	// 		meta = new Animal();
	// 		i = new Dog();
	// 		j = new Cat();
	// 		std::cout << std::endl;
	// 		std::cout << meta -> getType() << " " << std::endl;
	// 		std::cout << i -> getType() << " " << std::endl;
	// 		std::cout << j -> getType() << " " << std::endl;
	// 		meta->makeSound();
	// 		i->makeSound();
	// 		j->makeSound();
	// 		std::cout << std::endl;
	// 	}
	// 	catch (std::exception& e) {
	// 		std::cout << "Error: " << e.what() << std::endl;
	// 	}
	// 	delete meta;
	// 	delete i;
	// 	delete j;
	// 	std::cout << std::endl;
	// }
	{
		std::cout << SET_B_YLW "Runtime Polymorphism" RESET  << std::endl;
		Animal*	animals[ELE_COUNT] = {nullptr};
		try {
			for (int i = 0; i < ELE_COUNT; i++){
				if (i % 2)
					animals[i] = new Cat();
				else 
					animals[i] = new Dog();
			}
			std::cout << std::endl;
			for (int i = 0; i < ELE_COUNT; i++)
				animals[i] -> makeSound();
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;			
		}
		std::cout << std::endl;
		for (int i = 0; i < ELE_COUNT; i++)
			delete animals[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

// throw std::bad_alloc();