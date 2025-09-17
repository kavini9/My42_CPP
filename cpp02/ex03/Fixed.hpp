/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:45:46 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/17 20:25:54 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int					_value;
		static const int	_fracBitWid  = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float fValue);
		Fixed&	operator=(const Fixed& other);
		~Fixed();
		
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&		min(Fixed& fix1 ,Fixed& fix2);
		static Fixed&		max(Fixed& fix1 ,Fixed& fix2);
		static const Fixed&	min(const Fixed& fix1 ,const Fixed& fix2);
		static const Fixed&	max(const Fixed& fix1 ,const Fixed& fix2);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif