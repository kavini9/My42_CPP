/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:22:52 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/02 22:21:34 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

#define SET_B_YLW	"\033[1;33m"
#define RESET		"\033[0m"

int main() {
	DiamondTrap a("Alpha");
	DiamondTrap b("Beta");

	std::cout << std::endl;

	ScavTrap* scav;
	FragTrap* frag;

	scav = &a;
	frag = &a;
	// ScavTrap g("Gamma");
	// FragTrap o("Omega");
	
	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Printing attribute values of DiamondTrap" RESET  << std::endl;
	std::cout << "hitPoints: " << b.getHitPoints() << std::endl;
	std::cout << "energyPoints: " << b.getEnergyPoints() << std::endl;
	std::cout << "attackDamage: " << b.getAttackDamage() << std::endl;

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Printing attribute values of ScavTrap*" RESET  << std::endl;
	std::cout << "hitPoints: " << scav -> getHitPoints() << std::endl;
	std::cout << "energyPoints: " << scav -> getEnergyPoints() << std::endl;
	std::cout << "attackDamage: " << scav -> getAttackDamage() << std::endl;

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Printing attribute values of ScavTrap*" RESET  << std::endl;
	std::cout << "hitPoints: " << frag -> getHitPoints() << std::endl;
	std::cout << "energyPoints: " << frag -> getEnergyPoints() << std::endl;
	std::cout << "attackDamage: " << frag -> getAttackDamage() << std::endl;
	
	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Alpha attacks Beta." RESET  << std::endl;
	a.attack("Beta");
	b.takeDamage(5);

	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Beta gets repaird and attacks Alpha." RESET << std::endl;
	b.beRepaired(2);
	b.attack("Alpha");
	a.takeDamage(3);

	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Beta goes to gate keper mode." RESET << std::endl;
	b.guardGate();

	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Beta requests high five." RESET << std::endl;
	b.highFivesGuys();

	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Beta annouces who he is." RESET << std::endl;
	b.whoAmI();
	
	std::cout << SET_B_YLW "Test: Functionality of virtual functions." RESET << std::endl;
	DiamondTrap* c;
	ClapTrap* d;

	c = &a;
	d = &a;

	c -> attack("Beta");
	d -> attack("Beta");

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Behaviour of destructors with new." RESET << std::endl;
	DiamondTrap* e = new DiamondTrap("Eta");
	delete e;
	
	std::cout << std::endl;
	
	return (0);
}