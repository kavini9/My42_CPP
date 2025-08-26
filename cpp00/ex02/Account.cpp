/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:45:28 by wweerasi          #+#    #+#             */
/*   Updated: 2025/08/26 19:45:30 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) 
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << initial_deposit << ";"
	<< "created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void) 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

int Account::getNbAccounts(void) {return _nbAccounts;}

int Account::getTotalAmount(void) {return _totalAmount;}

int Account::getNbDeposits(void) {return _totalNbDeposits;}

int Account::getNbWithdrawals(void) {return _totalNbWithdrawals;}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
	<< "total:" << _totalAmount << ";"
	<< "deposits:" << _totalNbDeposits << ";"
	<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
	<< "p_amount:" << _amount << ";"
	<< "deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	std::cout << "amount:" << _amount << ";" 
	<< "nb_deposits:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "p_amount:" << _amount << ";"
	<< "withdrawal:";
	if (checkAmount() > withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout  << withdrawal << ";"
		<< "amount:" <<  _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return true;
	}
	else
	{
		std::cout << "refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount(void) const { return _amount;}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp()
{
	char datetime_format[18];
	time_t timestamp = time(NULL);
	strftime(datetime_format, 18, "[%Y%m%d_%H%M%S]", std::localtime(&timestamp));
	std::cout << datetime_format << " ";
}




