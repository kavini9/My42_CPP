/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:45:52 by wweerasi          #+#    #+#             */
/*   Updated: 2025/09/22 19:08:09 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
// #include <iomanip>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// std::cout << "my_tests-----------------------------------------------" << std::endl;
	// Fixed c(10);
	// Fixed d(15);
	// Fixed e(10.75f);
	// Fixed f(15.0625f);
	// Fixed g(10);
	// Fixed h(10.75f);
	// Fixed i(8388608);
	// Fixed j(16777216);
	// Fixed k(8388608.29296875f);

	// std::cout << "< & >:" << std::endl;
	// std::cout << "10 < 15			:" << (c < d) << std::endl;
	// std::cout << "10 > 15			:" << (c > d) << std::endl;
	// std::cout << "10.75 < 15.0625		:" << (e < f) << std::endl;
	// std::cout << "10.75 > 15.0625		:" << (e > f) << std::endl;
	// std::cout << "10 < 15.0625		:" << (c < f) << std::endl;
	// std::cout << "10.75 < 15		:" << (e < d) << std::endl;
	// std::cout << "10 > 15.0625		:" << (c > f) << std::endl;
	// std::cout << "10.75 > 15		:" << (e > d) << std::endl;
	// std::cout << std::endl;

	// std::cout << "<= " << std::endl;
	// std::cout << "10 <= 15		:" << (c <= d) << std::endl;
	// std::cout << "10 <= 10		:" << (c <= g) << std::endl;
	// std::cout << "15 <= 10		:" << (d <= c) << std::endl;
	// std::cout << "10.75 <= 15.0625	:" << (e <= f) << std::endl;
	// std::cout << "10.75 <= 10.75	:" << (e <= h) << std::endl;
	// std::cout << "15.0625 <= 10.75	:" << (f <= e) << std::endl;
	// std::cout << "10 <= 10.75		:" << (c <= e) << std::endl;
	// std::cout << "10.75 <= 10		:" << (e <= d) << std::endl;
	// std::cout << std::endl;

	// std::cout << ">= " << std::endl;
	// std::cout << "10 >= 15		:" << (c >= d) << std::endl;
	// std::cout << "10 >= 10		:" << (c >= g) << std::endl;
	// std::cout << "15 >= 10		:" << (d >= c) << std::endl;
	// std::cout << "10.75 >= 15.0625	:" << (e >= f) << std::endl;
	// std::cout << "10.75 >= 10.75	:" << (e >= h) << std::endl;
	// std::cout << "15.0625 >= 10.75	:" << (f >= e) << std::endl;
	// std::cout << "10 >= 10.75		:" << (c >= e) << std::endl;
	// std::cout << "10.75 >= 10		:" << (e >= d) << std::endl;
	// std::cout << std::endl;

	// std::cout << "== " << std::endl;
	// std::cout << "10 == 15		:" << (c == d) << std::endl;
	// std::cout << "10 == 10		:" << (c == g) << std::endl;
	// std::cout << "10.75 == 10.75	:" << (e == h) << std::endl;
	// std::cout << "15.0625 == 10.75	:" << (f == e) << std::endl;
	// std::cout << "10 == 10.75		:" << (c == e) << std::endl;
	// std::cout << std::endl;

	// std::cout << "!= " << std::endl;
	// std::cout << "10 != 15		:" << (c != d) << std::endl;
	// std::cout << "10 != 10		:" << (c != g) << std::endl;
	// std::cout << "10.75 != 10.75	:" << (e != h) << std::endl;
	// std::cout << "15.0625 != 10.75	:" << (f != e) << std::endl;
	// std::cout << "10 != 10.75		:" << (c != e) << std::endl;
	// std::cout << std::endl;

	// Fixed l(5);
	// Fixed m(2);
	// Fixed n(10.5f);
	// Fixed o(3.25f);

	// std::cout << "+ :" << std::endl;
	// std::cout << "5 + 2			:" << (l + m) << std::endl;
	// std::cout << "10.5 + 3.25		:" << (n + o) << std::endl;
	// std::cout << "5 + 3.25		:" << (l + o) << std::endl;
	// std::cout << "10.5 + 2		:" << (n + m) << std::endl;
	// std::cout << std::endl;

	// std::cout << "- :" << std::endl;
	// std::cout << "5 - 2			:" << (l - m) << std::endl;
	// std::cout << "10.5 - 3.25		:" << (n - o) << std::endl;
	// std::cout << "5 - 3.25		:" << (l - o) << std::endl;
	// std::cout << "5 - 10.5		:" << (l - m) << std::endl;
	// std::cout << std::endl;

	// std::cout << "* :" << std::endl;
	// std::cout << "5 * 2			:" << (l * m) << std::endl;
	// std::cout << "10.5 * 3.25		:" << std::setprecision(10) << (n * o) << std::endl;
	// std::cout << "5 * 3.25		:" << std::setprecision(10) << (l * o) << std::endl;
	// std::cout << "10.5 * 2		:" << std::setprecision(10) << (n * m) << std::endl;
	// std::cout << std::endl;

	// std::cout << "/ :" << std::endl;
	// std::cout << "5 / 2			:" << std::setprecision(10) << (l / m) << std::endl;
	// std::cout << "10.5 / 3.25		:" << std::setprecision(10) << (n / o) << std::endl;
	// std::cout << "5 / 3.25		:" << std::setprecision(10) << (l / o) << std::endl;
	// std::cout << "10.5 / 2		:" << std::setprecision(10) << (n / m) << std::endl;
	// std::cout << std::endl;

	// std::cout << "pre/post increment/decrement---------------------------" << std::endl;
	// Fixed p(1);

	// std::cout << "p					:" << std::setprecision(10) << p << std::endl;
	// std::cout << "++p (pre-inc)		:" << std::setprecision(10) << ++p << std::endl;
	// std::cout << "p after ++p		:" << std::setprecision(10) << p << std::endl;
	// std::cout << "p++ (post-inc)		:" << std::setprecision(10) << p++ << std::endl;
	// std::cout << "p after p++ 		:" << std::setprecision(10) << p << std::endl;
	// std::cout << "--p (pre-dec)		:" << std::setprecision(10) << --p << std::endl;
	// std::cout << "p after --p		:" << std::setprecision(10) << p << std::endl;
	// std::cout << "p-- (post-dec)		:" << std::setprecision(10) << p-- << std::endl;
	// std::cout << "p after p--		:" << std::setprecision(10) << p << std::endl;
	// std::cout << std::endl;

	// std::cout << "overflow_in_arithmetic-------------------------------" << std::endl;
	// Fixed q(2000000);
	// Fixed r(12345.75f);
	// Fixed s(8388607);        // 2^23 - 1
	// Fixed t(255.99f);

	// std::cout << "2,000,000 + 12345.75	:" << std::setprecision(10) << (q + r) << std::endl;
	// std::cout << "2,000,000 - 12345.75	:" << std::setprecision(10) << (q - r) << std::endl;
	// std::cout << "2,000,000 * 12345.75	:" << std::setprecision(10) << (q * r) << std::endl;
	// std::cout << "2,000,000 / 12345.75	:" << std::setprecision(10) << (q / r) << std::endl;

	// std::cout << "nearMax + 1		:" << std::setprecision(10) << (s + Fixed(1)) << std::endl;
	// std::cout << "nearMax * 2		:" << std::setprecision(10) << (s * Fixed(2)) << std::endl;
	// std::cout << "nearMax * (-2)		:" << std::setprecision(10) << (s * Fixed(-2)) << std::endl;
	// std::cout << "nearMax - (-2)		:" << std::setprecision(10) << (s - Fixed(-2)) << std::endl;
	// std::cout << "nearMax / 0.5		:" << std::setprecision(10) << (s / Fixed(0.5f)) << std::endl;

	// std::cout << "fractional overflow check----------------------------" << std::endl;
	// Fixed u(1.00390625f);	//1 + 1/256
	// Fixed v(1.00390620f);

	// std::cout << "fracEdge1.00390625f	:" << std::setprecision(10) << u << std::endl;
	// std::cout << "fracEdge2.00390620f	:" << std::setprecision(10) << v << std::endl;
	// std::cout << "fracEdge1 == fracEdge2	:" << (u == v) << std::endl;
	// std::cout << "fracEdge1 != fracEdge2	:" << (u != v) << std::endl;

	return 0;
}