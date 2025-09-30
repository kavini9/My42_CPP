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

#define SET_B_YLW	"\033[1;33m"
#define RESET		"\033[0m"

int main() {
	ClapTrap a("Alpha");
	ClapTrap b("Beta");
	ClapTrap c("Delta");
	ClapTrap d;
	d = c;
	ClapTrap e("Eta");
	ClapTrap g(e);

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
	std::cout << SET_B_YLW "Scene: Alpha attacks Beta in a loop until loosing all energy points and tries to get repaired." RESET << std::endl;
	for (int i = 0; i < 10; i++) {
		a.attack("Beta");
		b.takeDamage(2);
	}
	a.beRepaired(5); 

	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Delta attacks Eta causing damage more than 10 and Eta tries to get repaired." RESET << std::endl;
	d.attack("Eta");
	g.takeDamage(15);
	g.beRepaired(15);

	std::cout << std::endl;
	std::cout << SET_B_YLW "Scene: Delta tries to get repaired causing overflow (UINT_MAX = 4,294,967,295)." RESET << std::endl;
	d.beRepaired(UINT_MAX - 5);
	
	
	std::cout << std::endl;
	return (0);
}