/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:01:04 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/19 22:32:20 by wweerasi         ###   ########.fr       */
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
		Point& operator=(const Point& other) = delete;
		~Point();

		const Fixed& x(void) const;
		const Fixed& y(void) const;
};

#endif