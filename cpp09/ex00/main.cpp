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

void validateFileFormat(const char* fileName, const char* fileFormat) {
    if (std::filesystem::path(fileName).extension() != fileFormat)
		throw(std::runtime_error("Invalid file format."));
}

void openFile(std::ifstream& fileStream, const char* fileName)
{
	fileStream.open(fileName);
	if (!fileStream.is_open())
		throw(std::runtime_error("Error: could not open file."));
}

int main(int ac, char** av)
{
	if (ac != 2) {
		std::cerr << "Invalid argument(s)." << std::endl
		<< "Usage: ./btc <file_name>" << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		std::ifstream dbFile;
		std::ifstream queryFile;
		validateFileFormat("data.csv", ".csv");
		validateFileFormat(av[1], ".txt");
		openFile(dbFile, "data.csv");
		openFile(queryFile, av[1]);

		BitcoinExchange btc;

		btc.loadDatabase(dbFile);
		btc.queryDatabase(queryFile);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

}