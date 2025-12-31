/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:22:52 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/03 19:33:52 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

#define SET_B_YLW	"\033[1;33m"
#define RESET		"\033[0m"

int main() {
	DiamondTrap a("Alpha");
	DiamondTrap b("Beta");

	FragTrap* frag;
	ScavTrap* scav;
	ClapTrap* clap;

	frag = &a;
	scav = &a;
	clap = &a;
	
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
	std::cout << "static_hitPoints: " << ScavTrap::getStatHitPoints() << std::endl;
	std::cout << "static_energyPoints: " << ScavTrap::getStatEnergyPoints() << std::endl;
	std::cout << "static_attackDamage: " << ScavTrap::getStatAttackDamage() << std::endl;

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Printing attribute values of FragTrap*" RESET  << std::endl;
	std::cout << "hitPoints: " << frag -> getHitPoints() << std::endl;
	std::cout << "energyPoints: " << frag -> getEnergyPoints() << std::endl;
	std::cout << "attackDamage: " << frag -> getAttackDamage() << std::endl;
	std::cout << "static_hitPoints: " << FragTrap::getStatHitPoints() << std::endl;
	std::cout << "static_energyPoints: " << FragTrap::getStatEnergyPoints() << std::endl;
	std::cout << "static_attackDamage: " << FragTrap::getStatAttackDamage() << std::endl;

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Printing attribute values of ClapTrap*" RESET  << std::endl;
	std::cout << "hitPoints: " << clap -> getHitPoints() << std::endl;
	std::cout << "energyPoints: " << clap -> getEnergyPoints() << std::endl;
	std::cout << "attackDamage: " << clap -> getAttackDamage() << std::endl;
	std::cout << "static_hitPoints: " << ClapTrap::getStatHitPoints() << std::endl;
	std::cout << "static_energyPoints: " << ClapTrap::getStatEnergyPoints() << std::endl;
	std::cout << "static_attackDamage: " << ClapTrap::getStatAttackDamage() << std::endl;
	
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
	std::cout << SET_B_YLW "Scene: Beta goes to gate keeper mode." RESET << std::endl;
	b.guardGate();

	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Beta requests high five." RESET << std::endl;
	b.highFivesGuys();

	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Beta annouces who he is." RESET << std::endl;
	b.whoAmI();

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Copy constructor and Printing attribute values." RESET << std::endl;
	DiamondTrap e(b);
	std::cout << "Beta_hitPoints: " << b.getHitPoints() << std::endl;
	std::cout << "Beta_energyPoints: " << b.getEnergyPoints() << std::endl;
	std::cout << "Beta_attackDamage: " << b.getAttackDamage() << std::endl;
	std::cout << "Eta_hitPoints: " << e.getHitPoints() << std::endl;
	std::cout << "Eta_energyPoints: " << e.getEnergyPoints() << std::endl;
	std::cout << "Eta_attackDamage: " << e.getAttackDamage() << std::endl;

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Copy Assignment Operator and Printing attribute values." RESET << std::endl;
	DiamondTrap a_;
	a_ = a;
	std::cout << "Alpha_hitPoints: " << a.getHitPoints() << std::endl;
	std::cout << "Alpha_energyPoints: " << a.getEnergyPoints() << std::endl;
	std::cout << "Alpha_attackDamage: " << a.getAttackDamage() << std::endl;
	std::cout << "Alpha__hitPoints: " << a_.getHitPoints() << std::endl;
	std::cout << "Alpha__energyPoints: " << a_.getEnergyPoints() << std::endl;
	std::cout << "Alpha__attackDamage: " << a_.getAttackDamage() << std::endl;
	
	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Functionality of virtual functions." RESET << std::endl;
	DiamondTrap* c;
	ClapTrap* d;

	c = &a;
	d = &a;

	c -> attack("Beta");
	d -> attack("Beta");

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Behaviour of destructors with new." RESET << std::endl;
	DiamondTrap* t = new(std::nothrow) DiamondTrap("Theta");
	if (t != nullptr)
		delete t;
		
	std::cout << std::endl;
	
	return (0);
}