/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:16:45 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/18 22:16:46 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define SET_B_YLW	"\033[1;33m"
#define SET_YLW		"\033[33m"
#define RESET		"\033[0m"

int main()
{
	{
		std::cout << SET_B_YLW "Default Constructor Instantiation" RESET  << std::endl;
		try{
			Bureaucrat b0;
			std::cout << "b0: " << b0 << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Successfull Prameterized Constructor Instantiation and GradeTooHigh Exception" RESET  << std::endl;
		try {
			Bureaucrat b1("Paperclip", 150);			
			std::cout << "b1: " << b1 << std::endl;
			for (int i = 1; i < 150; i++)
				 b1.incrementGrade();
			std::cout << "b1: " << b1 << std::endl;
			b1.incrementGrade();		
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Successfull Prameterized Constructor Instantiation and GradeTooLow Exception" RESET  << std::endl;
		try {
			Bureaucrat b2("Stapleton", 1);			
			std::cout << "b2: " << b2 << std::endl;
			for (int i = 1; i < 150; i++)
				 b2.decrementGrade();
			std::cout << "b2: " << b2 << std::endl;
			b2.decrementGrade();		
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Copy Constructor Instantiation" RESET  << std::endl;
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
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Copy Assignment Operator" RESET  << std::endl;
		try {
			Bureaucrat b5("Inkley", 100);
			Bureaucrat b6;
			b6 = b5;
			std::cout << "b5: " << b5 << std::endl;
			std::cout << "b6: " << b6 << std::endl;
			b5.incrementGrade();
			std::cout << "b5: " << b5 << std::endl;
			std::cout << "b6: " << b6 << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "GradeTooHigh Exception at Instantiation" RESET  << std::endl;
		try {
			Bureaucrat b7("Stampwell", 0);				
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "GradeTooLow Exception at Instantiation" RESET  << std::endl;
		try {
			Bureaucrat b8("Filemore", 200);				
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}
