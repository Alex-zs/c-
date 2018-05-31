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
