/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:21 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/19 22:39:22 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::loadDatabase(std::ifstream& fileStream) {
	std::string line;
	std::regex dbRegex(R"(^(\d{4}-\d{2}-\d{2}),(\d+(?:\.\d+)?)$)");
	std::smatch matches;

	while (std::getline(fileStream, line)) {
		if (!std::regex_match(line, matches, dbRegex)) {continue;}
		std::string dateStr = matches[1].str();
		double rate = std::stod(matches[2].str());
		std::pair<std::string, double> dataPair = std::make_pair(dateStr, rate);
		_database.insert(dataPair);
	}
}

void BitcoinExchange::queryDatabase(std::ifstream& queryFile) const 
{
	std::string line;
	std::regex headerRegex(R"(^\s*date\s*\|\s*value\s*$)");
	std::regex queryRegex(R"(^((\d{4})-(\d{2})-(\d{2}))\s*\|\s*(-?\d+(?:\.\d+)?)$)");
	std::smatch matches;

	if (std::getline(queryFile, line) && !std::regex_match(line, headerRegex))
		throw std::runtime_error("Invalid query file header");

	while (std::getline(queryFile, line)) {
		try {
			if (!std::regex_match(line, matches, queryRegex))
				throw std::runtime_error("Error: bad input => " + line);

			std::string dateStr	= matches[1].str();
			std::chrono::year	year{std::stoi(matches[2].str())};
			std::chrono::month	month{static_cast<unsigned>(std::stoi(matches[3].str()))};
			std::chrono::day	day{static_cast<unsigned>(std::stoi(matches[4].str()))};
			double value		= std::stod(matches[5].str());

			if (!std::chrono::year_month_day{year, month, day}.ok())
				throw std::runtime_error("Error: bad input => " + dateStr);
			if (value < 0)
				throw std::runtime_error("Error: not a positive number.");
			if (value > 1000)
				throw std::runtime_error("Error: too large a number.");

			auto it = _database.upper_bound(dateStr);
			if (it == _database.begin())
				throw std::runtime_error("Error: no data available prior to " + it -> first);
			--it;
			double rate = it->second;
			double result = value * rate;
			std::cout << dateStr << " => " << value << " = " << result << std::endl;

		} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}	
}
