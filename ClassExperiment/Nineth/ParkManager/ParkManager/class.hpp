//
//  class.hpp
//  ParkManager
//
//  Created by 陈开拓 on 2018/5/24.
//  Copyright © 2018年 陈开拓. All rights reserved.
//

#ifndef class_hpp
#define class_hpp

#include <stdio.h>

#endif /* class_hpp */
#include <string>
#include <iostream>
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


