//
//  class.cpp
//  ParkManager
//
//  Created by 陈开拓 on 2018/5/24.
//  Copyright © 2018年 陈开拓. All rights reserved.
//

#include "class.hpp"

using namespace std;

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

void Park::showInfo(){
    cout << "停车场目前停放了" << now << "辆汽车:" ;
    for(int i = 0; i < car; i++){
        if(spaces[i] != NULL){
            cout << spaces[i]->getCarNum() << ",";
        }
    }
    cout << "共收入" << money << "元停车费" << endl;
}

void Park::enterCar(Automobile *newCar){
    for(int i = 0; i < car; i++){
        if (spaces[i] == NULL){
            spaces[i] = newCar;
            break;
        }
    }
    now = now + 1;
}

void Park::leaveCar(Automobile *newCar, int count){
    for(int i = 0; i < car; i++){
        if(spaces[i] == newCar){
            spaces[i] = NULL;
            break;
        }
    }
    money += count;
    now--;
}

Automobile::Automobile(string carNum):carNum(carNum){
}

string Automobile::getCarNum(){
    return carNum;
}

Truck::Truck(string carNum, double load):Automobile(carNum),load(load){
}

void Truck::enter(Park * park){
    if(park->checkout()){
        park->enterCar(this);
        cout << this->getCarNum() << "进入停车场，分配停车位" << endl;
    }
    else{
        cout << "无法为" << this->getCarNum() << "分配停车位" << endl;
    }
}

void Truck::leave(Park * park){
    park->leaveCar(this, 3);
    cout << this->getCarNum() << "离开停车场，缴纳停车费3元" << endl;
}

Car::Car(string carNum, string brand):brand(brand),Automobile(carNum){
    
}

void Car::enter(Park * park){
    if(park->checkout()){
        park->enterCar(this);
        cout << this->getCarNum() << "进入停车场，分配停车位" << endl;
    }
    else{
        cout << "无法为" << this->getCarNum() << "分配停车位" << endl;
    }
}

void Car::leave(Park * park){
    park->leaveCar(this, 1);
    cout << this->getCarNum() << "离开停车场，缴纳停车费1元" << endl;
}

Bus::Bus(string carNum, int people):people(people),Automobile(carNum){
    
}

void Bus::enter(Park * park){
    if(park->checkout()){
        park->enterCar(this);
        cout << this->getCarNum() << "进入停车场，分配停车位" << endl;
    }
    else{
        cout << "无法为" << this->getCarNum() << "分配停车位" << endl;
    }
}

void Bus::leave(Park * park){
    park->leaveCar(this, 2);
    cout << this->getCarNum() << "离开停车场，缴纳停车费2元" << endl;
}
