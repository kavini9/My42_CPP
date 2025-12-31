/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:00:54 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/22 19:14:35 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p) {

	const Fixed d1((b.x() - a.x()) * (p.y() - a.y()) - (b.y() - a.y()) * (p.x() - a.x()));
	const Fixed d2((c.x() - b.x()) * (p.y() - b.y()) - (c.y() - b.y()) * (p.x() - b.x()));
	const Fixed d3((a.x() - c.x()) * (p.y() - c.y()) - (a.y() - c.y()) * (p.x() - c.x()));
	
	return ((d1.toFloat() < 0 && d2.toFloat() < 0 && d3.toFloat() < 0)
		|| (d1.toFloat() > 0 && d2.toFloat() > 0 && d3.toFloat() > 0));
}