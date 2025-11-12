#include <iostream>
#include "Account.hpp"

/* --- Constructor creation --- */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
    std::cout << "---";
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit) {
    _totalAmount += _amount;
    _nbDeposits ++;
    std::cout << "Index:" << _accountIndex << ";";
    std::cout << "Amount:" << _amount << ";";
    std::cout << "created";
    std::cout << std::endl;
}

// GET
int Account::getNbAccounts() {return _nbAccounts++; }
int Account::getTotalAmount() {return _totalAmount++; }
int Account::getNbDeposits() {return _totalNbDeposits++; }
int Account::getNbWithdrawals() {return _totalNbWithdrawals++; }
void Account::displayAccountsInfos() {
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << ";";
    std::cout << std::endl;
}

void Account::displayStatus() const { 
    {
        std::cout << "Index:" << _accountIndex << ";";
        std::cout << "Amount:" << _amount << ";";
        std::cout << "deposits:" << _totalNbDeposits << ";";
        std::cout << "withdrawals:" << _totalNbWithdrawals << ";";
        std::cout << std::endl;
    }
    {
        std::cout << "Index:" << _accountIndex << ";";
        std::cout << std::endl;
    }

}

// SET
void Account::makeDeposit( int deposit ) { _totalAmount += deposit; }
bool Account::makeWithdrawal( int withdraw ) {_totalAmount -= withdraw; }
int Account::checkAmount() const {return _totalAmount; }

