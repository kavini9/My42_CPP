/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:04:55 by wweerasi          #+#    #+#             */
/*   Updated: 2026/01/31 20:55:02 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define SET_B_BLK	"\033[1;30m"
#define RESET		"\033[0m"

template <typename T>
void print(const T& var)
{
    std::cout << var << "	|	";;
}

template <typename T>
void add10(T& val)
{
	val += 5;
}
template <typename T>
void add_(T& str)
{
	str += "_";
}

int main() {
	int					arr_i[] = {25, 99, 125, 49, 94};
	const int			arr_const_i[] = {25, 99, 125, 49, 94};
	float				arr_f[] = {0.125f, 99.99f, 125.25f, 49.90f, 94.0f, -1.50f, 88.8f};
	char				arr_c[] = {'q', 'w', 'e', 'r', 't', 'y'};
	std::string			arr_s[] = {"Hello", "Hola", "Moi", "Aloha"};
	const std::string   arr_const_s[] = {"cyan", "navy", "bage"};
	// char*				arr_str[] = {"sea", "sky", "forests"};
	const char*			arr_const_str[] = {"winter", "spring", "summer", "fall"};
	const char* const	arr_const_strarr[] = {"one", "two", "three"};
	
	std::cout << SET_B_BLK "--- Integer Array ---" RESET << std::endl;
	::iter(arr_i, std::size(arr_i), print<int>);
	std::cout << std::endl;
	::iter(arr_i, std::size(arr_i), add10<int>);
	::iter(arr_i, std::size(arr_i), print<int>);
	std::cout << std::endl;
	
	std::cout << std::endl << SET_B_BLK "--- Const Integer Array ---" RESET << std::endl;
	::iter(arr_const_i, std::size(arr_const_i), print<const int>);
	std::cout << std::endl;
	// ::iter(arr_const_i, std::size(arr_const_i), add10<const int>);
	// ::iter(arr_const_i, std::size(arr_const_i), print<const int>);
	// std::cout << std::endl;

	std::cout << std::endl << SET_B_BLK "--- Float Array ---" RESET << std::endl;
	::iter(arr_f, std::size(arr_f), print<float>);
	std::cout << std::endl;
	::iter(arr_f, std::size(arr_f), add10<float>);
	::iter(arr_f, std::size(arr_f), print<float>);
	std::cout << std::endl;

	std::cout << std::endl << SET_B_BLK "--- Char Array ---" RESET << std::endl;
	::iter(arr_c, std::size(arr_c), print<char>);
	std::cout << std::endl;
	::iter(arr_c, std::size(arr_c), add10<char>);
	::iter(arr_c, std::size(arr_c), print<char>);
	std::cout << std::endl;

	std::cout << std::endl << SET_B_BLK "--- String Object Array ---" RESET << std::endl;
	::iter(arr_s, std::size(arr_s), print<std::string>);
	std::cout << std::endl;
	::iter(arr_s, std::size(arr_s), add_<std::string>);
	::iter(arr_s, std::size(arr_s), print<std::string>);
	std::cout << std::endl;
	
	std::cout << std::endl << SET_B_BLK "--- Const String Object Array ---" RESET << std::endl;
	::iter(arr_const_s, std::size(arr_const_s), print<const std::string>);
	std::cout << std::endl;
	// ::iter(arr_const_s, std::size(arr_const_s), add_<const std::string>);
	// ::iter(arr_const_s, std::size(arr_const_s), print<const std::string>);
	// std::cout << std::endl;

	// std::cout << std::endl << SET_B_BLK "--- Char Pointer Array ---" RESET << std::endl;
	// ::iter(arr_str, std::size(arr_str), print<char*>);
	// std::cout << std::endl;
	// ::iter(arr_str, std::size(arr_str), add_<char*>);
	// ::iter(arr_str, std::size(arr_str), print<char*>);
	// std::cout << std::endl;

	std::cout << std::endl << SET_B_BLK "--- Const Char Pointer Array ---" RESET << std::endl;
	::iter(arr_const_str, std::size(arr_const_str), print<const char*>);
	std::cout << std::endl;
	// ::iter(arr_const_str, std::size(arr_const_str), add_<const char*>);
	// ::iter(arr_const_str, std::size(arr_const_str), print<const char*>);
	// std::cout << std::endl;
	
	std::cout << std::endl << SET_B_BLK "--- Const (Const Char Pointer) Array ---" RESET << std::endl;
	::iter(arr_const_strarr, std::size(arr_const_strarr), print<const char*>);
	std::cout << std::endl << std::endl;
	// ::iter(arr_const_strarr, std::size(arr_const_strarr), add_<const char*>);
	// ::iter(arr_const_strarr, std::size(arr_const_strarr), print<const char*>);
	// std::cout << std::endl;
}

