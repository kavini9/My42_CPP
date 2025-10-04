/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:14:01 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/04 21:53:23 by wweerasi         ###   ########.fr       */
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
		std::cout << SET_B_YLW "Animal inheritance" RESET  << std::endl;
		const Animal* meta = new(std::nothrow) Animal();
		const Animal* i = new(std::nothrow) Dog();
		const Animal* j = new(std::nothrow) Cat();
		std::cout << std::endl;
		std::cout << meta -> getType() << " " << std::endl;
		std::cout << i -> getType() << " " << std::endl;
		std::cout << j -> getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound();
		j->makeSound();
		std::cout << std::endl;
		if (meta != nullptr) {delete meta;}
		if (i != nullptr) {delete i;}
		if (j != nullptr) {delete j;}
		std::cout << std::endl;
	}
	{
		std::cout << SET_B_YLW "WrongAnimal inheritance" RESET  << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* k = new WrongCat();
		std::cout << std::endl;
		std::cout << meta -> getType() << " " << std::endl;
		std::cout << k -> getType() << " " << std::endl;
		meta->makeSound();
		k->makeSound();
		std::cout << std::endl;
		if (meta != nullptr) {delete meta;}
		if (k != nullptr) {delete k;}
	}
	
	return 0;
}