/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:00:54 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/19 23:05:41 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p) {
	
	// std::cout << a.x().toFloat() << std::endl;
	// std::cout << a.y().toFloat() << std::endl;
	// std::cout << b.x().toFloat() << std::endl;
	// std::cout << b.y().toFloat() << std::endl;
	// std::cout << c.x().toFloat() << std::endl;
	// std::cout << c.y().toFloat() << std::endl;
	// std::cout << p.x().toFloat() << std::endl;
	// std::cout << p.y().toFloat() << std::endl;	
	
	const Fixed d1((b.x() - a.x()) * (p.y() - a.y()) - (b.y() - a.y()) * (p.x() - a.x()));
	const Fixed d2((c.x() - b.x()) * (p.y() - b.y()) - (c.y() - b.y()) * (p.x() - b.x()));
	const Fixed d3((a.x() - c.x()) * (p.y() - c.y()) - (a.y() - c.y()) * (p.x() - c.x()));
	
	// const Fixed d1((b.x().toFloat() - a.x().toFloat()) * (p.y().toFloat() - a.y().toFloat()) - (b.y().toFloat() - a.y().toFloat()) * (p.x().toFloat() - a.x().toFloat()));
	// const Fixed d2((c.x().toFloat() - b.x().toFloat()) * (p.y().toFloat() - b.y().toFloat()) - (c.y().toFloat() - b.y().toFloat()) * (p.x().toFloat() - b.x().toFloat()));
	// const Fixed d3((a.x().toFloat() - c.x().toFloat()) * (p.y().toFloat() - c.y().toFloat()) - (a.y().toFloat() - c.y().toFloat()) * (p.x().toFloat() - c.x().toFloat()));
	
	// std::cout << d1 << std::endl;
	// std::cout << d2 << std::endl;
	// std::cout << d3 << std::endl;
	
	return ((d1.toFloat() < 0 && d2.toFloat() < 0 && d3.toFloat() < 0)
		|| (d1.toFloat() > 0 || d2.toFloat() > 0 || d3.toFloat() > 0));
}