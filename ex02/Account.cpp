#include <iostream>
#include <ctime>
#include <locale>
#include <iterator>
#include "Account.hpp"

/* --- Constructor creation --- */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
}

Account::~Account(void) 
{
	_displayTimestamp();
	std::cout << "Index:" << _accountIndex << ";";
	std::cout << "Amount:" << _amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit) {
    _displayTimestamp();
	_totalAmount += _amount;
    std::cout << "Index:" << _accountIndex << ";";
    std::cout << "Amount:" << _amount << ";";
    std::cout << "created";
    std::cout << std::endl;
}

// GET
int Account::getNbAccounts() {return _nbAccounts; }
int Account::getTotalAmount() {return _totalAmount; }
int Account::getNbDeposits() {return _totalNbDeposits; }
int Account::getNbWithdrawals() {return _totalNbWithdrawals; }
void Account::displayAccountsInfos() {
	_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << ";";
    std::cout << std::endl;
}
void Account::displayStatus() const { 
    {
		_displayTimestamp();
        std::cout << "Index:" << _accountIndex << ";";
        std::cout << "Amount:" << _amount << ";";
        std::cout << "deposits:" << _nbDeposits << ";";
        std::cout << "withdrawals:" << _nbWithdrawals << ";";
        std::cout << std::endl;
    }
}

// SET
void Account::makeDeposit( int deposit ) 
{
	_displayTimestamp();
	if (deposit < 0)
		return ;
	_nbDeposits ++;
	_totalNbDeposits++;
	std::cout << "Index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "Amount:" << _amount + deposit<< ";";
	std::cout << "nb_deposits:" << _nbDeposits << ";";
	std::cout << std::endl;
 	_amount += deposit; 
	_totalAmount += deposit;
}  //incr acount
	
bool Account::makeWithdrawal( int withdraw ) 
{ //implement w
	_displayTimestamp();
	std::cout << "Index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdraw > _amount)
	{
		std::cout << "withdrawal:refused\n";
		return false;
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "deposit:" << withdraw << ";";
	std::cout << "Amount:" << _amount - withdraw << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
	_amount -= withdraw;
	_totalAmount -= withdraw;
	return true;
}
int Account::checkAmount() const {return _totalAmount; }

void Account::_displayTimestamp(void)
{
	char tt[100];
	std::time_t now = std::time(NULL);
	std::strftime(tt, 100, "%Y%m%d_%H%M%S", std::localtime(&now));
	std::cout << "[" << tt << "] ";
}

