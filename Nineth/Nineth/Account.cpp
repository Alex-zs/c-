//
//  Account.cpp
//  Nineth
//
//  Created by 陈开拓 on 2018/5/24.
//  Copyright © 2018年 陈开拓. All rights reserved.
//

#include "Account.hpp"
#include <iostream>

using namespace std;

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

