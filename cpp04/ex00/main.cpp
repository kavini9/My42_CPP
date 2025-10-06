/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:14:01 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/06 22:55:07 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define SET_B_YLW	"\033[1;33m"
#define RESET		"\033[0m"

int main()
{
	{
		const Animal* meta = nullptr;
		const Animal* i = nullptr;
		const Animal* j = nullptr;
		try {
			std::cout << SET_B_YLW "Animal inheritance" RESET  << std::endl;
			meta = new Animal();
			i = new Dog();
			j = new Cat();
			std::cout << std::endl;
			std::cout << meta -> getType() << " " << std::endl;
			std::cout << i -> getType() << " " << std::endl;
			std::cout << j -> getType() << " " << std::endl;
			meta->makeSound();
			i->makeSound();
			j->makeSound();
			std::cout << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		delete meta;
		delete i;
		delete j;
		std::cout << std::endl;
	}
	{
		const WrongAnimal* meta = nullptr;
		const WrongAnimal* k = nullptr;
		try {
			std::cout << SET_B_YLW "WrongAnimal inheritance" RESET  << std::endl;
			meta = new WrongAnimal();
			k = new WrongCat();
			std::cout << std::endl;
			std::cout << meta -> getType() << " " << std::endl;
			std::cout << k -> getType() << " " << std::endl;
			meta->makeSound();
			k->makeSound();
			std::cout << std::endl;			
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		delete meta;
		delete k;
		std::cout << std::endl;
	}
	return 0;
}

//throw std::bad_alloc();