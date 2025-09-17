/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:01:04 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/17 21:24:23 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float xValue, const float yValue);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		const Fixed& getX(void) const;
		const Fixed& getY(void) const;
};

#endif