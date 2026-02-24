/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:30:08 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/24 14:19:20 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <limits>
#include "Span.hpp"

#define SET_B_BLK	"\033[1;30m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

int main() {
	{
		std::cout << SET_B_BLK "Normal functionality - Subject example" RESET << std::endl;
		try {
			Span span = Span(5);

			span.addNumber(6); 
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(11);
			std::cout << "span		:" << span << std::endl;
			std::cout << "shortestSpan	:" << span.shortestSpan() << std::endl;
			std::cout << "longestSpan	:" << span.longestSpan() << std::endl;	
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Span has no space - size(0)" RESET << std::endl;
		try {
			Span span(0);

			span.addNumber(6);
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}	
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Span has no space - size(5)" RESET << std::endl;
		try {
			Span span(1);
			span.addNumber(6);
			span.addNumber(3);
			span.addNumber(17);
			span.addNumber(9);
			span.addNumber(11);
			span.addNumber(15);
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}	
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Add range to span" RESET << std::endl;
		try {
			Span span(10);
			std::vector<int> range{1, 2, 3, 4, 5};
			span.addNumber(6);
			span.addNumber(3);
			span.addNumber(17);
			span.addRange(range.begin(), range.end());
			span.addNumber(11);
			span.addNumber(15);
			std::cout << "span		:" << span << std::endl;
			std::cout << "shortestSpan	:" << span.shortestSpan() << std::endl;
			std::cout << "longestSpan	:" << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}	
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Span has no space to add range" RESET << std::endl;
		try {
			Span span(10);
			std::vector<int> range{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			span.addNumber(6);
			span.addNumber(3);
			span.addNumber(17);
			span.addRange(range.begin(), range.end());
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}	
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Span is empty : shortestSpan throws exception" RESET << std::endl;
		try {
			Span span(0);
			std::cout << "span		:" << span << std::endl;
			std::cout << "shortestSpan	:" << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}	
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Span is empty : longestSpan throws exception" RESET << std::endl;
		try {
			Span span(0);
			std::cout << "span		:" << span << std::endl;
			std::cout << "longestSpan	:" << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Span has single element : shortestSpan throws exception" RESET << std::endl;
		try {
			Span span(1);
			span.addNumber(6);
			std::cout << "span		:" << span << std::endl;
			std::cout << "shortestSpan	:" << span.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}	
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Span has single element : longestSpan throws exception" RESET << std::endl;
		try {
			Span span(1);
			span.addNumber(6);
			std::cout << "span		:" << span << std::endl;
			std::cout << "longestSpan	:" << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Span can store 10 000 numbers" RESET << std::endl;
		try {
			Span span(10000);
        	srand((long) &span);
        	for (int i = 0; i < 10000; i++)
            	span.addNumber(rand());
			std::cout << "span size	:" << span.getSpanSize() << std::endl;
			std::cout << "shortestSpan	:" << span.shortestSpan() << std::endl;
			std::cout << "longestSpan	:" << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
		{
		std::cout << std::endl;
		std::cout << SET_B_BLK "int overflow conditions" RESET << std::endl;
		try {
			Span span(4);
			span.addNumber(std::numeric_limits<int>::max());
			span.addNumber(std::numeric_limits<int>::min());
			span.addNumber(5);
			span.addNumber(6);
			std::cout << "span		:" << span << std::endl;
			std::cout << "shortestSpan	:" << span.shortestSpan() << std::endl;
			std::cout << "longestSpan	:" << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
}
