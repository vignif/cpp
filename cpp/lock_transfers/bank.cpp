#include "bank.hpp"
#include <thread>

Bank::Bank(std::string name) : _name(name)
{
    std::cout << "Created bank: "
              << name << std::endl;
}

void Bank::printAccounts()
{
    std::cout << "Bank Entries: \n"
              << std::endl;
    for (int i = 0; i < _accounts.size(); ++i)
    {
        _accounts.at(i)->print();
    }
}

void Bank::addAccount(Account &acc)
{
    _accounts.push_back(&acc);
}

void Bank::addAccount(Account *acc)
{
    _accounts.emplace_back(acc);
}

void Bank::transfer(Account &from, Account &to, float num)
{
    _threads.emplace_back(std::thread(from.transfer, std::ref(from), std::ref(to), num));
}

void Bank::compute()
{
    for (int i = 0; i < _threads.size(); ++i)
    {
        // join the threads
        _threads.at(i).join();
    }
}
