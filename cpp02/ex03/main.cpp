/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:45:52 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/19 21:33:07 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const p);

int main( void ) {
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point p(5, 5);

	bool isInTriangle = bsp(a, b, c, p);
	std::cout << "P is " << (isInTriangle ? "inside" : "outside") << " the triangle\n";
}