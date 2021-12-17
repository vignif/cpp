#include "account.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <thread>

Account::~Account()
{
    std::cout << "Account " << _name << " destructed" << std::endl;
}

Account::Account(std::string name) : _name(name)
{
    std::cout << "Account " << _name << " created" << std::endl;
}

Account::Account(std::string name, float balance) : _name(name),
                                                    _balance(balance)
{
    std::cout << "Account: " << _name << " created with balance \t" << _balance << std::endl;
}

Account::Account(const Account &)
{
    std::cout << "Called copy constructor" << std::endl;
}

std::string Account::getName() const
{
    return _name;
}

void Account::print() const
{
    std::cout << "Account: " << _name << " with balance \t" << _balance << std::endl;
}

void Account::withdraw(const float &amount)
{
    _balance -= amount;
}

void Account::deposit(const float &amount)
{
    _balance += amount;
}

void Account::transfer(Account &from, Account &to, float num)
{
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(from._balance_mtx, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to._balance_mtx, std::defer_lock);

    // lock both unique_locks without deadlock
    if (from.getName() == to.getName())
    {
        std::cout << "Can't transfer to same user" << std::endl;
    }
    else
    {
        std::lock(lock1, lock2);
        std::cout << "From: \t" << from.getName() << "\t to: " << to.getName() << " \t" << num << std::endl;
        from.withdraw(num);
        to.deposit(num);
    }

    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
}
