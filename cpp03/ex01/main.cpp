/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:22:52 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/03 19:34:05 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define SET_B_YLW	"\033[1;33m"
#define RESET		"\033[0m"

int main() {
	ScavTrap a("Alpha");
	ScavTrap b("Beta");

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
	std::cout << SET_B_YLW "Test: Copy constructor and Printing attribute values." RESET << std::endl;
	ScavTrap e(b);
	std::cout << "Beta_hitPoints: " << b.getHitPoints() << std::endl;
	std::cout << "Beta_energyPoints: " << b.getEnergyPoints() << std::endl;
	std::cout << "Beta_attackDamage: " << b.getAttackDamage() << std::endl;
	std::cout << "Eta_hitPoints: " << e.getHitPoints() << std::endl;
	std::cout << "Eta_energyPoints: " << e.getEnergyPoints() << std::endl;
	std::cout << "Eta_attackDamage: " << e.getAttackDamage() << std::endl;

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Copy Assignment Operator and Printing attribute values." RESET << std::endl;
	ScavTrap a_;
	a_ = a;
	std::cout << "Alpha_hitPoints: " << a.getHitPoints() << std::endl;
	std::cout << "Alpha_energyPoints: " << a.getEnergyPoints() << std::endl;
	std::cout << "Alpha_attackDamage: " << a.getAttackDamage() << std::endl;
	std::cout << "Alpha__hitPoints: " << a_.getHitPoints() << std::endl;
	std::cout << "Alpha__energyPoints: " << a_.getEnergyPoints() << std::endl;
	std::cout << "Alpha__attackDamage: " << a_.getAttackDamage() << std::endl;
	

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Functionality of virtual functions." RESET << std::endl;
	ScavTrap* c;
	ClapTrap* d;

	c = &a;
	d = &a;

	c -> attack("Beta");
	d -> attack("Beta");

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Behaviour of destructors with new." RESET << std::endl;
	ScavTrap* t = new(std::nothrow) ScavTrap("Theta");
	if (t != nullptr)
		delete t;
	
	std::cout << std::endl;
	return (0);
}