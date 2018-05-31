//
//  Account.hpp
//  Nineth
//
//  Created by 陈开拓 on 2018/5/24.
//  Copyright © 2018年 陈开拓. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>

#endif /* Account_hpp */
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
