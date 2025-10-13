/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:28:40 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/13 19:18:09 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#define SET_B_YLW	"\033[1;33m"
#define SET_YLW		"\033[33m"
#define RESET		"\033[0m"

int main()
{
	{
		std::cout << SET_B_YLW "Example Test" RESET  << std::endl;
		IMateriaSource* src = nullptr;
		ICharacter* me = nullptr;
		ICharacter* bob = nullptr;
		try {
			src = new MateriaSource();
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
			me = new Character("me");
			AMateria* tmp;
			tmp = src->createMateria("ice");
			me->equip(tmp);
			tmp = src->createMateria("cure");
			me->equip(tmp);
			bob = new Character("bob");
			me->use(0, *bob);
			me->use(1, *bob);
		}
			catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "My Test" RESET  << std::endl;
		IMateriaSource* src = nullptr;
		ICharacter* me = nullptr;
		ICharacter* bob = nullptr;
		AMateria* mat1 = nullptr;
		AMateria* mat2 = nullptr;
		try {
			src = new MateriaSource();
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
			me = new Character("me");
			mat1 = src->createMateria("ice");
			mat2 = src->createMateria("cure");
			std::cout << SET_YLW "Step :Equip character and test euip for index out of range." RESET << std::endl;
			me->equip(mat1);//1
			me->equip(mat2);//2
			me->equip(mat1);//3
			me->equip(mat2);//4
			me->equip(mat1);//5
			std::cout << SET_YLW "Step: Use equipped materia and test use for indexes out of range." RESET << std::endl;
			bob = new Character("bob");
			me->use(0, *bob);
			me->use(1, *bob);
			me->use(2, *bob);
			me->use(3, *bob);
			me->use(4, *bob);
			std::cout << SET_YLW "Step: Unequip last two blueprints." RESET << std::endl;
			me->unequip(2);
			me->unequip(3);
			std::cout << SET_YLW "Step: Use equipped materia and test indexes unequipped." RESET << std::endl;
			me->use(0, *bob);
			me->use(1, *bob);
			me->use(2, *bob);
			me->use(3, *bob);
			std::cout << SET_YLW "Step: Unequip all materia and test unequip for indexes out of range ." RESET << std::endl;
			me->unequip(0);
			me->unequip(1);
			me->unequip(2);
			me->unequip(3);
			me->unequip(4);
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;			
		}
		delete mat1;
		delete mat2;
		delete bob;
		delete me;
		delete src;
	}
	return 0;
}

// throw std::bad_alloc();