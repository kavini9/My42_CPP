/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:30 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/19 22:39:31 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <filesystem>
#include <fstream>
#include "BitcoinExchange.hpp"

void openFile(std::ifstream& fileStream, const char* fileName)
{
	fileStream.open(fileName);
	if (!fileStream.is_open())
		throw(std::runtime_error("could not open file."));
}

int main(int ac, char** av)
{
	if (ac != 2) {
		std::cerr << SET_RED "Error: invalid no. of argument(s)." << std::endl
		<< "Usage: ./btc <file_name>" RESET << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		std::ifstream dbFile;
		std::ifstream queryFile;
		if (std::filesystem::path(av[1]).extension() != ".txt")
			throw(std::runtime_error("invalid file format."));
		openFile(dbFile, "data.csv");
		openFile(queryFile, av[1]);

		BitcoinExchange btc;

		btc.loadDatabase(dbFile);
		btc.queryDatabase(queryFile);
	} catch (const std::exception& e) {
		std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		return (EXIT_FAILURE);
	}
}