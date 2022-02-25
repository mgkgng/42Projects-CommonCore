/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-kang <minguk.gaang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:11:07 by min-kang          #+#    #+#             */
/*   Updated: 2022/02/25 13:10:12 by min-kang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>

Account::Account(int initial_deposit) {
	// this init.
	this->_accountIndex = this->_amount;
	this->_amount += initial_deposit;

	// static init.
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;

	// display
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << initial_deposit
				<< ";created" << std::endl;
	return ;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
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
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex 
				<< ";p_amount:" << _amount
				<< ";deposits:" << deposit
				<< ";amount:" << _amount + deposit
				<< ";nb_deposits:" << _nbDeposits + 1
				<< std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
}				

bool	Account::makeWithdrawal( int withdrawal ){
	if (_amount >= withdrawal) {
		_displayTimestamp();
		std::cout	<< "index:" << _accountIndex 
					<< ";p_amount:" << _amount
					<< ";withdrawal:" << withdrawal
					<< ";amount:" << _amount - withdrawal
					<< ";nb_deposits:" << _nbWithdrawals + 1
					<< std::endl;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;
		return (true);
	}
	else {
		_displayTimestamp();
		std::cout	<< "index:" << _accountIndex 
					<< ";p_amount:" << _amount
					<< ";deposits:refused" << std::endl;
		return (false);
	}
}
int		Account::checkAmount( void ) const {
	return (this->_amount);
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;

}

void	Account::_displayTimestamp( void ){
	time_t now = time(0);
	struct tm *t = localtime(&now);

	std::cout << "[" << (t->tm_year + 1900) << std::to_string(t->tm_mon)
		<< "_" + std::to_string(t->tm_hour) << std::to_string(t->tm_min)
		<< std::to_string(t->tm_sec) + "] ";
}