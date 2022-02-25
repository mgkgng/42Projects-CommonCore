/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:11:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 12:18:29 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	// this init.
	_accountIndex = _nbAccounts;
	_amount += initial_deposit;

	// static init.
	_nbAccounts++;
	_totalAmount += _amount;

	// display
	_displayTimestamp();
	std::cout << ";amount:" << initial_deposit << ";created" << std::endl;
	return ;
}

Account::~Account(void){
	std::cout << ";closed" << std::endl;
	return ;
}

int Account::getNbAccounts(void){
	return (_nbAccounts);
}

int Account::getTotalAmount(void){
	return (_totalAmount);
}

int	Account::getNbDeposits(void){
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts 
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ){
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else
		return (false);
}
int		Account::checkAmount( void ) const {

}
void	Account::displayStatus( void ) const {
	int i;
	for (i = this->_accountIndex; i < this->_nbAccounts; i++) {
		_displayTimestamp();
		std::cout	<< "index:" << i 
					<< ";amount:" << _amount
					<< ";deposits:" << _nbDeposits
					<< ";withdrawals:" << _nbWithdrawals
					<< std::endl;
	}
}

void	Account::_displayTimestamp( void ){
	time_t now = time(0);
	struct tm *t = localtime(&now);

	std::cout << "[" << (t->tm_year + 1900) << std::to_string(t->tm_mon)
		<< "_" + std::to_string(t->tm_hour) << std::to_string(t->tm_min)
		<< std::to_string(t->tm_sec) + "] ";
}