/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:17:05 by wweerasi          #+#    #+#             */
/*   Updated: 2025/11/10 16:42:54 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define SET_B_BLK	"\033[1;30m"
#define SET_YLW		"\033[33m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

int main()
{
	{
		std::cout << SET_B_BLK "Successfull Prameterized Constructor Instantiation" RESET  << std::endl;
		try {
			Form f("VacationRequestForm", 125, 100);
			std::cout << "form: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Grade to sign triggers GradeTooHigh Exception" RESET  << std::endl;
		try {
			Form f("CoffeeApprovalForm", 0, 100);
			std::cout << "form: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Grade to sign triggers GradeTooLow Exception" RESET  << std::endl;
		try {
			Form f("ExpenseClaimForm", 200, 100);
			std::cout << "form: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Grade to execute triggers GradeTooHigh Exception" RESET  << std::endl;
		try {
			Form f("ElevatorAccessRequestForm", 125, -1);
			std::cout << "form: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Grade to execute triggers GradeTooLow Exception" RESET  << std::endl;
		try {
			Form f("ExtensionRequestForm", 125, 151);
			std::cout << "form: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Copy Constructor Instantiation" RESET  << std::endl;
		try {
			Form f1("LeaveRequestForm", 125, 150);
			Form f2(f1);
			std::cout << "form1: " << f1 << std::endl;
			std::cout << "form2: " << f2 << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Form gets signed succesfully" RESET  << std::endl;
		try {
			Form f("ITSupportRequestForm", 100, 50);
			Bureaucrat b("Clara", 75);
			std::cout << "form: " << f << std::endl;
			std::cout << "bureaucrat: " << b << std::endl;
			b.signForm(f);
			std::cout << "form: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Form fails to get signed due to GradeTooLow" RESET  << std::endl;
		try {
			Form f("MaintenanceRequestForm", 100, 50);
			Bureaucrat b("Harl", 125);
			std::cout << "form: " << f << std::endl;
			std::cout << "bureaucrat: " << b << std::endl;
			b.signForm(f);
			std::cout << "form: " << f << std::endl;
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << SET_B_BLK "Form is already signed" RESET  << std::endl;
		try {
			Form f("TemporaryWorkaroundApprovalForm", 100, 50);
			Bureaucrat b1("Deborah", 90);
			Bureaucrat b2("Derek", 80);
			std::cout << "form: " << f << std::endl;
			std::cout << "bureaucrat: " << b1 << std::endl;
			b1.signForm(f);
			std::cout << "f: " << f << std::endl;
			std::cout << "bureaucrat: " << b2 << std::endl;
			b2.signForm(f);	
		}
		catch (std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	std::cout << std::endl;
}