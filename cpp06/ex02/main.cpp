/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:24:15 by wweerasi          #+#    #+#             */
/*   Updated: 2026/01/20 21:30:15 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base* generate(void) {
	switch (rand() % 3) {
		case 0:
			std::cout << "Generated type: A" << std::endl;
			return new(std::nothrow) A();
		case 1:
			std::cout << "Generated type: B" << std::endl;
			return new(std::nothrow) B();
		default:
			std::cout << "Generated type: C" << std::endl;
			return new(std::nothrow) C();
	}
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "Identified type by pointer:	A" << std::endl;
    else if (dynamic_cast<B*>(p))
		std::cout << "Identified type by pointer:	B" << std::endl;
    else if (dynamic_cast<C*>(p))
		std::cout << "Identified type by pointer:	C" << std::endl;
}

void identify(Base& p)
{
    try { 
		(void) dynamic_cast<A&>(p);
		std::cout << "Identified type by reference:	A" << std::endl;
	} catch (std::bad_cast&) {}
    try { 
		(void) dynamic_cast<B&>(p);
		std::cout << "Identified type by reference:	B" << std::endl;
	} catch (std::bad_cast&) {}
    try {
		(void) dynamic_cast<C&>(p);
		std::cout << "Identified type by reference:	C" << std::endl;
	} catch (std::bad_cast&) {}
}

int main(){
	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		Base *obj =  generate();
		if (obj != nullptr) {
			identify(obj);
			identify(*obj);
			delete obj;
			std::cout << std::endl;
		}	
	}
}