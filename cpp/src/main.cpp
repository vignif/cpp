#include "main.hpp"
#include "bank.hpp"

int main()
{
    std::cout << "Hello World!"
              << "\n";

    Bank B("BCC");

    Account A1("Ciccio", 200);
    Account A2("Bob", 100);
    Account A3("Alex", 300);
    B.addAccount(&A3);
    B.addAccount(A1);
    B.addAccount(A2);
    B.transfer(A1, A2, 10);
    B.transfer(A3, A2, 20);
    B.transfer(A2, A2, 30);
    B.compute();
    //B.printAccounts();
    return 0;
}