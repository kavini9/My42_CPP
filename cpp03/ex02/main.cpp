/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:22:52 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/29 21:39:42 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#define SET_B_YLW	"\033[1;33m"
#define RESET		"\033[0m"

int main() {
	FragTrap a("Alpha");
	FragTrap b("Beta");

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
	std::cout << SET_B_YLW "Scene: Beta requests high five." RESET << std::endl;
	b.highFivesGuys();

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Functionality of virtual functions." RESET << std::endl;
	FragTrap* c;
	ClapTrap* d;

	c = &a;
	d = &a;

	c -> attack("Beta");
	d -> attack("Beta");

	std::cout << std::endl;
	std::cout << SET_B_YLW "Test: Behaviour of destructors with new." RESET << std::endl;
	FragTrap* e = new FragTrap("Eta");
	delete e;
	
	std::cout << std::endl;
	return (0);
}