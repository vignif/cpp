#include "account.hpp"

#include <iostream>
#include <thread>
#include <vector>

class Bank
{
public:
    Bank(std::string name);

    void printAccounts();

    void addAccount(Account &acc);

    void addAccount(Account *acc);

    void transfer(Account &from, Account &to, float num);

    void compute();

private:
    std::vector<std::thread> _threads;
    std::vector<Account *> _accounts;
    std::string _name;
};
