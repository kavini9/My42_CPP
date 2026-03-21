/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:26 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/19 22:39:27 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <chrono>

#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

class BitcoinExchange {
	private:
		std::map<std::string, double> _database;

	public:
		BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange& other) = default;
		BitcoinExchange& operator=(const BitcoinExchange& other) = default;
		~BitcoinExchange() = default;

		void loadDatabase(std::ifstream& fileStream);
		void queryDatabase(std::ifstream& date) const;
};

#endif