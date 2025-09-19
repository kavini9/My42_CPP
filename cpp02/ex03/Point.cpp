/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:01:01 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/19 20:29:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed()) , _y(Fixed()) {}

Point::Point(const float xValue, const float yValue) 
	: _x(Fixed(xValue)), _y(Fixed(yValue)) {}

Point::Point(const Point& other) : _x(other._x) , _y(other._y) {}

Point::~Point() {}

const Fixed& Point::x(void) const {
	return (_x);
}

const Fixed& Point::y(void) const {
	return (_y);
}