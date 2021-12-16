
#include <mutex>

class Account
{
private:
    std::string _name;
    float _balance;
    mutable std::mutex _balance_mtx;

public:
    Account(std::string name);
    Account(std::string name, float balance);
    Account(const Account &);
    ~Account();
    std::string getName() const;
    void print() const;
    void withdraw(const float &amount);
    void deposit(const float &amount);
    static void transfer(Account &from, Account &to, float num);
};
