#include <iostream>
#include "Account.hpp"
using namespace std;


int main() {
    Account *accounts[3];
    accounts[0] = new SavingsAccount(100, 3);
    accounts[1] = new CheckingAccount(100, 5);
    accounts[2] = new CheckingAccount(50, 5);
    for (int i = 0; i < 3; i++) {
        cout << "第" << i + 1 << "次循环的结果:" << endl;
        accounts[i]->debit(200);
        accounts[i]->debit(40);
        accounts[i]->credit(50);
        accounts[i]->debit(49);
        accounts[i]->debit(43);
        accounts[i]->credit(1);
        cout << "账户的余额为:" << accounts[i]->getBalance() << endl;
    }
}




