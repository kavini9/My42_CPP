/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:16:45 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/10 18:25:49 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define SET_B_BLK	"\033[1;30m"
#define SET_YLW		"\033[33m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

int main()
{
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Successfull Prameterized Constructor Instantiation and GradeTooHigh Exception" RESET  << std::endl;
		try {
			Bureaucrat b1("Paperclip", 150);			
			std::cout << "b1: " << b1 << std::endl;
			for (int i = 1; i < 150; i++)
				 b1.incrementGrade();
			std::cout << "b1: " << b1 << std::endl;
			b1.incrementGrade();		
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Successfull Prameterized Constructor Instantiation and GradeTooLow Exception" RESET  << std::endl;
		try {
			Bureaucrat b2("Stapleton", 1);			
			std::cout << "b2: " << b2 << std::endl;
			for (int i = 1; i < 150; i++)
				 b2.decrementGrade();
			std::cout << "b2: " << b2 << std::endl;
			b2.decrementGrade();		
		}
		catch (std::exception& e) {
			std::cout <<  SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Copy Constructor Instantiation" RESET  << std::endl;
		try {
			Bureaucrat b3("Stampwell", 50);
			Bureaucrat b4(b3);
			std::cout << "b3: " << b3 << std::endl;
			std::cout << "b4: " << b4 << std::endl;
			b3.decrementGrade();
			std::cout << "b3: " << b3 << std::endl;
			std::cout << "b4: " << b4 << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "GradeTooHigh Exception at Instantiation" RESET  << std::endl;
		try {
			Bureaucrat b7("Stampwell", 0);				
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "GradeTooLow Exception at Instantiation" RESET  << std::endl;
		try {
			Bureaucrat b8("Filemore", 200);				
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
}
