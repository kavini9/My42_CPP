/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:05:43 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/24 20:15:25 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define SET_B_BLK	"\033[1;30m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

int main() {
	{
		std::cout << SET_B_BLK "Construction with no parameter" RESET  << std::endl;
		try{
			Array<int>			i;
			Array<float>		f;
			Array<char>			c;
			Array<char *>		str;
			Array<std::string>	s;

			std::cout << "i.size()	= " << i.size() << std::endl
						<< "f.size()	= " << f.size() << std::endl
						<< "c.size()	= " << c.size() << std::endl
						<< "str.size()	= " << str.size() << std::endl
						<< "s.size()	= " << s.size() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Construction with an unsigned int n as a parameter" RESET  << std::endl;
		try{
			unsigned int n = 7;
			Array<int>			i(n);
			Array<float>		f(n);
			Array<char>			c(n);
			Array<char *>		str(n);
			Array<std::string>	s(n);
			std::cout << "i.size()	= " << i.size() << "	i[0]	= " << i[0] << std::endl
						<< "f.size()	= " << f.size() << "	f[0]	= " << f[0] << std::endl
						<< "c.size()	= " << c.size() << "	c[0]	= " << c[0] << std::endl
						<< "str.size()	= " << str.size() << "	str[0]	= " << static_cast<void*>(str[0]) << std::endl
						<< "s.size()	= " << s.size() << "	s[0]	= "  << s[0] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Construction by copy constructor" RESET  << std::endl;
		try{
			unsigned int n = 7;
			Array<int>			a(n);
			int fibSeq = 1;
			for (unsigned int i = 0; i < n; i++) {
				a[i] = fibSeq;
				fibSeq += i;
			}
			Array<int>			b(a);
			std::cout << "a.size()	= " << a.size() << std::endl
						<< "b.size()	= " << b.size() << std::endl;
			std::cout << std::endl;
			std::cout << SET_B_BLK "original(a)	copy(b)" RESET  << std::endl;
			for (unsigned int i = 0; i < n; i++) {
				std::cout << "a[" << i << "] = " << a[i] << "	b[" << i << "] = " << b[i] << std::endl;
			}
			std::cout << std::endl;	
			std::cout << SET_B_BLK "a[i] - 5	b" RESET << std::endl;
			for (unsigned int i = 0; i < n; i++)
				a[i] -= 5;
			for (unsigned int i = 0; i < n; i++) {
				std::cout << "a[" << i << "] = " << a[i] << "	b[" << i << "] = " << b[i] << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Construction by copy assignment operator" RESET  << std::endl;
		try{
			unsigned int n = 10;
			Array<int>			a(n);
			int fibSeq = 1;
			for (unsigned int i = 0; i < n; i++) {
				a[i] = fibSeq;
				fibSeq += i;
			}
			Array<int>			b(a);
			std::cout << "a.size()	= " << a.size() << std::endl
						<< "b.size()	= " << b.size() << std::endl;
			std::cout << std::endl;	
			std::cout << SET_B_BLK "original(a)	copy(b)" RESET  << std::endl;
			for (unsigned int i = 0; i < n; i++) {
				std::cout << "a[" << i << "] = " << a[i] << "	b[" << i << "] = " << b[i] << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Out of bound exeption for operator []" RESET  << std::endl;
		try{
			unsigned int n = 3;
			Array<int>			a(n);
			int fibSeq = 1;
			for (unsigned int i = 0; i < n; i++) {
				a[i] = fibSeq;
				fibSeq += i;
			}
			std::cout << "a.size()	= " << a.size() << std::endl;
			std::cout << "a[" << n << "] = " << a[n] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Constant qualifier for operator []" RESET  << std::endl;
		try{
			unsigned int n = 7;
			Array<int>			a(n);
			Array<const int>	b(n);
			const Array<int>	c(n);
			int x = 5;
			a[1] = x;
			// b[1] = x;
			// c[1] = x;
			// //make member attributes public for testing
			// int y[] = {9,8,7,6};
			// a._data = y;
			// b._data = y;
			// c._data = y;			
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
		std::cout << std::endl;
	}
}

// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;
// 	return 0;
// }