#include <iostream>
#include "Account.hpp"
using namespace std;

class Account{
public:
    double balance;
    virtual void credit(double){}
    virtual bool debit(double){return false;}
    virtual double getBalance(){
        return balance;
    }
};
class CheckingAccount:public Account{
public:
    CheckingAccount(double, double);
    void credit(double);
    bool debit(double);
    double getBalance();
private:
    double fee;
};

class SavingsAccount:public Account{
public:
    SavingsAccount(double, double);
    double calculateInterest();
    void credit(double);
    bool debit(double);
    double getBalance();
private:
    double interestRate;
    
};

double CheckingAccount::getBalance(){
    return balance;
}

double SavingsAccount::getBalance(){
    return balance + calculateInterest();
}

void SavingsAccount::credit(double money){
    balance = balance + money;
}

bool SavingsAccount::debit(double money){
    if((balance - money) > 0){
        balance = balance - money;
        return true;
    }
    else{
        cout << "Debit amount exceeded account balance" << endl;
        return false;
    }
}


SavingsAccount::SavingsAccount(double balance, double interestRate):interestRate(interestRate){
    this->balance = balance;
}

double SavingsAccount::calculateInterest(){
    return balance * interestRate / 100.0;
}


CheckingAccount::CheckingAccount(double balance, double fee):fee(fee){
    this->balance = balance;
}

void CheckingAccount::credit(double money){
    if((balance+ money) > fee){
        balance = balance + money - fee;
    }
    else{
        cout << "Transaction fee exceeded account balance while crediting" << endl;
    }
}

bool CheckingAccount::debit(double money){
    if((balance - money) - fee > 0 ){
        balance = balance - money - fee;
        return true;
    }
    else{
        cout << "Transaction fee exceeded account balance while debiting" << endl;
        return false;
    }
}

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




