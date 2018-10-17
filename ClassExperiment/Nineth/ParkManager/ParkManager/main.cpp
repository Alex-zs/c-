//
//  main.cpp
//  ParkManager
//
//  Created by 陈开拓 on 2018/5/24.
//  Copyright © 2018年 陈开拓. All rights reserved.
//

#include <iostream>
#include "class.hpp"

using namespace std;

class Automobile;

class Park{
public:
    void showInfo();
    Park(int N);
    int getMoney(){return money;}
    int getNow(){return now;}
    int getCar(){return car;}
    void enterCar(Automobile * newCar);
    void leaveCar(Automobile * newCar,int count);
    bool checkout();
private:
    Automobile ** spaces;
    int money;
    int now;
    int car;
};


class Automobile{
public:
    string getCarNum();
    virtual void enter(Park *park) {}
    virtual void leave(Park *park){}
    virtual void pay(Park *park){}  //向停车场支付停车费
    Automobile(string carNum);
private:
    string carNum;
};

class Truck:public Automobile {
private:
    double load;
public:
    Truck(string carNum, double load);
    void enter(Park * park);
    void leave(Park * park);
    void pay();
    
};

class Car:public Automobile{
private:
    string brand;
public:
    Car(string carNum, string brand);
    void pay();
    void enter(Park * park);
    void leave(Park * park);
};

class Bus:public Automobile{
private:
    int people;
public:
    void pay();
    Bus(string carNum, int people);
    void enter(Park * park);
    void leave(Park * park);
};

Park::Park(int N){
    spaces = new Automobile * [N];
    for(int i = 0; i < N; i++){
        spaces[i] = NULL;
    }
    this->money = 0;
    this->now = 0;
    this->car = N;
}

bool Park::checkout(){
    for(int i=0; i < car; i++){
        if (spaces[i] == NULL){
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cout << "请输入停车位数量:";
    cin >> N;
    Park park(N);// 创建一个停车场对象
    Automobile *auto1 = new Car("鲁B-12345", "奥迪A6");
    Automobile *auto2 = new Truck("鲁B-23456", 15);
    Automobile *auto3 = new Bus("鲁B-34567", 50);
    Automobile *auto4 = new Car("鲁B-45678", "宝马320");
    auto1->enter(&park);
    auto2->enter(&park);
    auto1->leave(&park);
    auto3->enter(&park);
    
    park.showInfo();
    auto4->enter(&park);
    auto3->leave(&park);
    auto2->leave(&park);
    
    park.showInfo();
    
    return 0;
    
}
