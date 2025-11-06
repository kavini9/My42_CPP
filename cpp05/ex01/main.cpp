/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:17:05 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/06 18:37:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define SET_B_YLW	"\033[1;33m"
#define SET_YLW		"\033[33m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

int main()
{
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Successfull Prameterized Constructor Instantiation" RESET  << std::endl;
		try {
			Form f("VacationRequestForm", 125, 100);
			std::cout << "f: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Grade to sign triggers GradeTooHigh Exception" RESET  << std::endl;
		try {
			Form f("CoffeeApprovalForm", 0, 100);
			std::cout << "f: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Grade to sign triggers GradeTooLow Exception" RESET  << std::endl;
		try {
			Form f("ExpenseClaimForm", 200, 100);
			std::cout << "f: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Grade to execute triggers GradeTooHigh Exception" RESET  << std::endl;
		try {
			Form f("ElevatorAccessRequestForm", 125, -1);
			std::cout << "f: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Grade to execute triggers GradeTooLow Exception" RESET  << std::endl;
		try {
			Form f("ExtensionRequestForm", 125, 151);
			std::cout << "f: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Copy Constructor Instantiation" RESET  << std::endl;
		try {
			Form f1("LeaveRequestForm", 125, 150);
			Form f2(f1);
			std::cout << "f1: " << f1 << std::endl;
			std::cout << "f2: " << f2 << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Form gets signed succesfully" RESET  << std::endl;
		try {
			Form f("ITSupportRequestForm", 100, 50);
			Bureaucrat b("Clara", 75);
			std::cout << "f: " << f << std::endl;
			std::cout << "b: " << b << std::endl;
			b.signForm(f);
			//f.beSigned(b);
			std::cout << "f: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Form fails to get signed" RESET  << std::endl;
		try {
			Form f("MaintenanceRequestForm", 100, 50);
			Bureaucrat b("Harl", 125);
			std::cout << "f: " << f << std::endl;
			std::cout << "b: " << b << std::endl;
			b.signForm(f);
			// f.beSigned(b);
			std::cout << "f: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_YLW "Form is already signed" RESET  << std::endl;
		try {
			Form f("TemporaryWorkaroundApprovalForm", 100, 50);
			Bureaucrat b1("Deborah", 90);
			Bureaucrat b2("Derek", 80);
			std::cout << "f: " << f << std::endl;
			std::cout << "b1: " << b1 << std::endl;
			b1.signForm(f);
			// f.beSigned(b1);
			std::cout << "f: " << f << std::endl;
			std::cout << "b2: " << b2 << std::endl;
			b2.signForm(f);
			// f.beSigned(b2);
			
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
}