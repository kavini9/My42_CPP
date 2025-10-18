/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 21:14:01 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/18 21:19:42 by wweerasi         ###   ########.fr       */
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
	{
		std::cout << SET_B_YLW "Deep Copy Validation : Cat Copy Constructor" RESET  << std::endl;
		try {
			Cat catA;
			Brain* catBrainA = catA.getBrain();
			std::cout << std::endl;
			std::cout << "Cat A idea[0]: " << catBrainA -> getIdea(0) << std::endl;
			std::cout << "Cat A idea[1]: " << catBrainA -> getIdea(1) << std::endl;
			std::cout << "Cat A idea[2]: " << catBrainA -> getIdea(2) << std::endl;
			std::cout << "Cat A idea[3]: " << catBrainA -> getIdea(3) << std::endl;
			std::cout << "Cat A idea[100]: " << catBrainA -> getIdea(100) << std::endl;
			std::cout << std::endl;
			Cat catB(catA);
			std::cout << std::endl;
			std::cout << "Cat A brain pointer: " << catA.getBrain() << std::endl;
			std::cout << "Cat B brain pointer: " << catB.getBrain() << std::endl;
			std::cout << std::endl;
			Brain* catBrainB = catB.getBrain();
			catBrainB -> setIdea(0, "eat");
			catBrainB -> setIdea(1, "sleep");
			catBrainB -> setIdea(2, "roam");
			catBrainB -> setIdea(100, "do nothing");
			std::cout << "Cat B idea[0]: " << catBrainB -> getIdea(0) << std::endl;
			std::cout << "Cat B idea[1]: " << catBrainB -> getIdea(1) << std::endl;
			std::cout << "Cat B idea[2]: " << catBrainB -> getIdea(2) << std::endl;
			std::cout << "Cat B idea[3]: " << catBrainB -> getIdea(3) << std::endl;
			std::cout << std::endl;
			std::cout << "Cat A idea[0]: " << catBrainA -> getIdea(0) << std::endl;
			std::cout << "Cat A idea[1]: " << catBrainA -> getIdea(1) << std::endl;
			std::cout << "Cat A idea[2]: " << catBrainA -> getIdea(2) << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;			
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Deep Copy Validation : Dog Copy Constructor" RESET  << std::endl;
		try {
			Dog dogA;
			Dog dogB(dogA);
			std::cout << std::endl;
			std::cout << "Dog A brain pointer: " << dogA.getBrain() << std::endl;
			std::cout << "Dog B brain pointer: " << dogB.getBrain() << std::endl;
			std::cout << std::endl;		
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;			
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Deep Copy Validation : Cat Copy Assignment Operator" RESET  << std::endl;
		try {
			Cat catA;
			Cat catB;
			catB = catA;
			std::cout << std::endl;
			std::cout << "Cat A brain pointer: " << catA.getBrain() << std::endl;
			std::cout << "Cat B brain pointer: " << catB.getBrain() << std::endl;
			std::cout << std::endl;	
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;			
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Deep Copy Validation : Dog Copy Assignment Operator" RESET  << std::endl;
		try {
			Dog dogA;
			Brain* dogBrainA = dogA.getBrain();
			std::cout << std::endl;
			std::cout << "Dog A idea[0]: " << dogBrainA -> getIdea(0) << std::endl;
			std::cout << "Dog A idea[1]: " << dogBrainA -> getIdea(1) << std::endl;
			std::cout << "Dog A idea[2]: " << dogBrainA -> getIdea(2) << std::endl;
			std::cout << "Dog A idea[3]: " << dogBrainA -> getIdea(3) << std::endl;
			std::cout << "Dog A idea[100]: " << dogBrainA -> getIdea(100) << std::endl;
			std::cout << std::endl;
			Dog dogB;
			dogB = dogA;
			std::cout << std::endl;
			std::cout << "Dog A brain pointer: " << dogA.getBrain() << std::endl;
			std::cout << "Dog B brain pointer: " << dogB.getBrain() << std::endl;
			std::cout << std::endl;
			Brain* dogBrainB = dogB.getBrain();
			dogBrainB -> setIdea(0, "eat");
			dogBrainB -> setIdea(1, "sleep");
			dogBrainB -> setIdea(2, "roam");
			dogBrainB -> setIdea(100, "do nothing");
			std::cout << "Dog B idea[0]: " << dogBrainB -> getIdea(0) << std::endl;
			std::cout << "Dog B idea[1]: " << dogBrainB -> getIdea(1) << std::endl;
			std::cout << "Dog B idea[2]: " << dogBrainB -> getIdea(2) << std::endl;
			std::cout << "Dog B idea[3]: " << dogBrainB -> getIdea(3) << std::endl;
			std::cout << std::endl;
			std::cout << "Dog A idea[0]: " << dogBrainA -> getIdea(0) << std::endl;
			std::cout << "Dog A idea[1]: " << dogBrainA -> getIdea(1) << std::endl;
			std::cout << "Dog A idea[2]: " << dogBrainA -> getIdea(2) << std::endl;
			std::cout << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;			
		}
	}
	std::cout << std::endl;
	return 0;
}

// throw std::bad_alloc();