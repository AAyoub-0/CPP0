/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accounts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 03:16:24 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/08 17:13:55 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount - deposit)
			  << ";deposit:" << deposit << ";amount:" << _amount << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << (_amount + withdrawal)
			  << ";withdrawal:" << withdrawal << ";amount:" << _amount << std::endl;
	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
	std::time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);
	
	std::cout << "["
			<< (localTime->tm_year + 1900)
			<< std::setw(2) << std::setfill('0') << localTime->tm_mon + 1
			<< std::setw(2) << std::setfill('0') << localTime->tm_mday << "_"
			<< std::setw(2) << std::setfill('0') << localTime->tm_hour
			<< std::setw(2) << std::setfill('0') << localTime->tm_min
			<< std::setw(2) << std::setfill('0') << localTime->tm_sec
			<< "] ";
}
