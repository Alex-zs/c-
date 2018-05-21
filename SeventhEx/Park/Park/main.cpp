#include <iostream>
#include <string>

using namespace std;

class Automobile{
public:
    Automobile();
    string carNum;
};

Automobile::Automobile(){
    carNum ="";
}

class Park{
public:
    void showshowInfo();
    Park(int car);
    int getMoney(){return money;}
    int getNow(){return now;}
    int getCar(){return car;}
    void enterCar(Automobile * newCar) {
        for(int i=0; i<car; i++){
            if (spaces[i] == NULL){
                spaces[i] == newCar;
            }
        }
        now++;
    }
    void leaveCar(Automobile * newCar,int count){
        for(int i = 0; i < car; i++){
            if(spaces[i] == newCar){
                spaces[i] = NULL;
            }
        }
        money += count;
        now--;
    }
    bool checkout();
private:
    Automobile ** spaces;
    int money;
    int now;
    int car;
};

Park::Park(int car):now(0),money(0),car(car){
    spaces = new Automobile*[car];
    for(int i=0;i < car; i++){
        spaces[i] == NULL;
    }
}

bool Park::checkout(){
    for(int i=0; i < car; i++){
        if (spaces[i] == NULL){
            return true;
        }
    }
    return false;
}

class Truck:public Automobile {
private:
    double load;
public:
    Truck(string carNum, double load);
    void enter(Park park);
    void leave(Park park);
    void pay();

};

Truck::Truck(string carNum, double load):load(load){
    this->carNum = carNum;
}

void Truck::enter(Park park){
    if(park.checkout()){
        park.enterCar(this);
        cout << this->carNum << "进入停车场，分配停车位" << endl;
    }
    else{
        cout << "无法为" << this->carNum << "分配停车位" << endl;
    }
}

void Truck::leave(Park park){
    park.leaveCar(this, 3);
    cout << this->carNum << "离开停车场，缴纳停车费3元" << endl;
}


class Car:public Automobile{
private:
    string brand;
public:
    Car(string brand, string carNum);
    void pay();
    void enter(Park park);
    void leave(Park park);
};

Car::Car(string brand, string carNum):brand(brand){
    this->carNum = carNum;
}

void Car::enter(Park park){
    if(park.checkout()){
        park.enterCar(this);
        cout << this->carNum << "进入停车场，分配停车位" << endl;
    }
    else{
        cout << "无法为" << this->carNum << "分配停车位" << endl;
    }
}

void Car::leave(Park park){
    park.leaveCar(this, 1);
    cout << this->carNum << "离开停车场，缴纳停车费1元" << endl;
}
class Bus:public Automobile{
private:
    int people;
public:
    void pay();
    Bus(string carNum, int people);
    void enter(Park park);
    void leave(Park park);
};

Bus::Bus(string carNum, int people):people(people){
    this->carNum = carNum;
}

void Bus::enter(Park park){
    if(park.checkout()){
        park.enterCar(this);
        cout << this->carNum << "进入停车场，分配停车位" << endl;
    }
    else{
        cout << "无法为" << this->carNum << "分配停车位" << endl;
    }
}

void Bus::leave(Park park){
    park.leaveCar(this, 1);
    cout << this->carNum << "离开停车场，缴纳停车费2元" << endl;
}

int main(){
    int N;
    cout << "请输入停车位数量:";
    cin >> N;
    Park *park = new Park(N);
    Car car1("鲁B-12345","奥迪A6");
    car1.enter(*park);
    Truck truck("鲁B-23456", 15);
    truck.enter(*park);
    return 0;
    
}
