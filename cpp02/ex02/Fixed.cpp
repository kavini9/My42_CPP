/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:45:58 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/22 18:23:52 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	//std::cout << "Copy constructor called" << std::endl;
	_value = other.getRawBits();
}

Fixed::Fixed(const int value) {
	//std::cout << "Int constructor called" << std::endl;
	_value = value << _fracBitWid;
}

Fixed::Fixed(const float value) {
	//std::cout << "Float constructor called" << std::endl;
	_value = (int) roundf(value * (1 << _fracBitWid));
}

Fixed& Fixed::operator=(const Fixed& other) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

bool	Fixed::operator>(const Fixed& other) const {return (_value > other._value);}
bool	Fixed::operator<(const Fixed& other) const {return (_value < other._value);}
bool	Fixed::operator>=(const Fixed& other) const {return (_value >= other._value);}
bool	Fixed::operator<=(const Fixed& other) const {return (_value <= other._value);}
bool	Fixed::operator==(const Fixed& other) const {return (_value == other._value);}
bool	Fixed::operator!=(const Fixed& other) const {return (_value != other._value);}

Fixed	Fixed::operator+(const Fixed& other) const {return (Fixed(this -> toFloat() + other.toFloat()));}
Fixed	Fixed::operator-(const Fixed& other) const {return (Fixed(this -> toFloat() - other.toFloat()));}
Fixed	Fixed::operator*(const Fixed& other) const {return (Fixed(this -> toFloat() * other.toFloat()));}
Fixed	Fixed::operator/(const Fixed& other) const {return (Fixed(this -> toFloat() / other.toFloat()));}
		
Fixed&	Fixed::operator++() {
	++_value;
	return (*this);
}

Fixed&	Fixed::operator--() {
	--_value;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	++_value;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	--_value;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& fix1 ,Fixed& fix2) {return ((fix1 < fix2) ? fix1 : fix2);}
Fixed&	Fixed::max(Fixed& fix1 ,Fixed& fix2) {return ((fix1 > fix2) ? fix1 : fix2);}
const Fixed&	Fixed::min(const Fixed& fix1 ,const Fixed& fix2) {return ((fix1 < fix2) ? fix1 : fix2);}
const Fixed&	Fixed::max(const Fixed& fix1 ,const Fixed& fix2) {return ((fix1 > fix2) ? fix1 : fix2);}

int	Fixed::getRawBits(void) const {
	return _value;
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float) _value / (float) (1 << _fracBitWid));
}

int	Fixed::toInt(void) const {
	return (_value >> _fracBitWid);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}