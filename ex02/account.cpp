#include "Account.hpp"
#include <iostream>
#include <ctime>

    int Account::_nbAccounts = 0;
	int Account::_totalAmount = 0;
	int Account::_totalNbDeposits = 0;
	int Account::_totalNbWithdrawals = 0;

	void Account::_displayTimestamp( void )
    {
        char buffer[100];

        std::time_t now = time(NULL);
        std::tm* tm_ptr = std::localtime(&now);
        strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]" , tm_ptr);
        std::cout << buffer;
    }



    int Account::getNbAccounts()
    {
        return Account::_nbAccounts;
    }
	int Account::getTotalAmount()
    {
        return Account::_totalAmount;
    }
	int Account::getNbDeposits()
    {
        return Account::_totalNbDeposits;
    }
	int Account::getNbWithdrawals()
    {
        return Account::_totalNbWithdrawals;
    }
	void Account::displayAccountsInfos()
    {
         Account::_displayTimestamp();
            std::cout << " accounts:" << _nbAccounts << ";total:" << Account::getTotalAmount() <<  ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << '\n';
    }

    Account::Account(int initial_deposit)
    {
        Account::_displayTimestamp();
        this->_accountIndex = _nbAccounts;
        this->_nbDeposits = 0;
        this->_nbWithdrawals = 0;
        this->_amount = initial_deposit;
        std::cout << " index" << _accountIndex << ";amount:" << initial_deposit << ";" << "created\n";
        Account::_totalAmount += initial_deposit;
        _nbAccounts++;
    }
    Account::~Account()
    {
                Account::_displayTimestamp();
        std::cout << " index:" << _accountIndex <<  ";amount:" << checkAmount() << ";closed\n";
    }


	void Account::makeDeposit( int deposit )
    {
        Account::_displayTimestamp();
        std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount() <<";deposit:" << deposit;
        _amount += deposit;
        _nbDeposits ++;
        _totalAmount += deposit;
        _totalNbDeposits ++;
        std::cout << ";amount:" << checkAmount() <<";nb_deposits:" << _nbDeposits << '\n';

    }
	bool	Account::makeWithdrawal( int withdrawal )
    {
        if(withdrawal > checkAmount())
            {
                Account::_displayTimestamp();
                std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:refused\n";
                return 0;
            }
        Account::_displayTimestamp();
        std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount() <<";withdrawal:" << withdrawal;
        _amount -= withdrawal;
        _nbWithdrawals ++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals ++;
        std::cout << ";amount:" << checkAmount() <<";nb_withdrawals:" << _nbWithdrawals << '\n';

        return 1;
    }
	int		Account::checkAmount( void ) const
    {
        return _amount;
    }
	void Account::displayStatus( void ) const
    {
        Account::_displayTimestamp();
        std::cout << " index:" << _accountIndex <<  ";amount:" << checkAmount() <<";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << '\n';
    }