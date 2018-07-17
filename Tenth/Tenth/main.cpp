#include <iostream>
#include "class.h"
#include "Array.h"

#include<cassert>

using namespace std;

template<class T>
class Array{
private:
    T * list;
    int size;
public:
    Array(int sz=50);
    Array(const Array<T> &a);
    ~Array();
    Array<T>& operator = (const Array<T> &rhs);
    T & operator [] (int i);
    const T & operator [] (int i) const;
    operator T * ();
    operator const T*() const;
    int getSize() const;
    void resize(int sz);
};

template<class T>
Array<T>::Array(int sz){
    assert(sz >=0);
    size = sz;
    list = new T [size];
}

template<class T>
Array<T>::~Array(){
    delete []list;
}

template<class T>
Array<T>::Array(const Array<T>&a) {
    size = a.size;
    list = new T[size];
    for(int i = 0; i < size; i++){
        list[i] = a.list[i];
    }
}

template<class T>
Array<T>&Array<T>::operator=(const Array<T> &rhs) {
    if(&rhs != this) {
        if (size != rhs.size) {
            delete [] list;
            size = rhs.size;
            list = new T[size];
        }
        for(int i = 0; i < size; i++)
            list[i] = rhs.list[i];
    }
    return * this;
}


template<class T>
T &Array<T>::operator[] (int n) {
    assert(n >= 0 && n < size);
    return list[n];
}

template<class T>
const T &Array<T>::operator[] (int n) const {
    assert(n >= 0 && n < size);
    return list[n];
}

template<class T>
Array<T>::operator T* (){
    return list;
}

template<class T>
Array<T>::operator const T* () const {
    return list;
}

template<class T>
int Array<T>::getSize() const {
    return size;
}

template<class T>
void Array<T>::resize(int sz) {
    assert(sz >= 0);
    if(sz == size)
        return;
    T * newList = new T[sz];
    int n = (sz<size) ? sz :size;
    for(int i = 0; i < n; i++) {
        newList[i] = list[i];
    }
    delete [] list;
    list = newList;
    size = sz;
}

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
class Shape{
public:
    virtual double getCircumference() = 0;
    virtual void showInfo() = 0;
    string getShape();
    bool operator > (Shape * s){
        if(this->getCircumference() > s->getCircumference())
            return true;
        else
            return false;
    }
    Shape(string);
private:
    string shape;
};

class Circle:public Shape{
public:
    Circle(double);
    virtual double getCircumference();
    virtual void showInfo();
private:
    double radius;
};


class Rectangle:public Shape{
public:
    Rectangle(double, double);
    virtual double getCircumference();
    virtual void showInfo();
private:
    double length;
    double width;
};

class RightTriangle:public Shape{
public:
    RightTriangle(double, double);
    virtual double getCircumference();
    virtual void showInfo();
private:
    double side1;
    double side2;
};
Shape::Shape(string shape):shape(shape){
}

string Shape::getShape(){
    return shape;
}

Circle::Circle(double radius):Shape("圆"),radius(radius){
}

double Circle::getCircumference(){
    return 2 * 3.14 * radius;
}

void Circle::showInfo(){
    cout << "圆, 半径" << radius << ", 周长";
    cout  <<setiosflags(ios::fixed) << setprecision(2) << this->getCircumference() << endl;
}

Rectangle::Rectangle(double length, double width):length(length),width(width),Shape("长方形"){
}

double Rectangle::getCircumference(){
    return 2 * (length + width);
}

void Rectangle::showInfo(){
    cout << "长方形，长" << length ;
    cout << " 宽" << width << "，周长";
    cout  <<setiosflags(ios::fixed) << setprecision(2) << this->getCircumference() << endl;
}

RightTriangle::RightTriangle(double side1, double side2):side1(side1),side2(side2),Shape("三角形"){
}

double RightTriangle::getCircumference(){
    double side3 = sqrt((side1*side1) + (side2*side2));
    return side1 + side2 + side3;
}

void RightTriangle::showInfo(){
    cout << "三角形，直角边" << side1 << ", 直角边" << side2 ;
    cout << ", 周长" ;
    cout  <<setiosflags(ios::fixed) << setprecision(2)<< this->getCircumference() << endl;
}

int main() {
    Array<Shape*> shapeList(10);
    int shape = 0, count = 0;
    while (shape != -1) {
        cout << "Please choose the shape:(1:Circle,2:Rectangle,3:RightTriangle,-1:exit):";
        cin >> shape;
        if (shape == 1) {
            double radius;
            cout << "Please input the radius:";
            cin >> radius;
            if(count == shapeList.getSize()){
                shapeList.resize(count * 2);
            }
            shapeList[count] = new Circle(radius);
            count++;
        }
        if (shape == 2) {
            double length;
            double width;
            cout << "Please input the length and the width:";
            cin >> length >> width;
            if(count == shapeList.getSize()){
                shapeList.resize(count * 2);
            }
            shapeList[count] = new Rectangle(length, width);
            count++;
        }
        if (shape == 3) {
            double side1;
            double side2;
            cout << "Please input the side and another side:";
            cin >> side1 >> side2;
            if(count == shapeList.getSize()){
                shapeList.resize(count * 2);
            }
            shapeList[count] = new RightTriangle(side1, side2);
            count++;
        }
    }
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            Shape *temp_i = shapeList[i];
            Shape *temp_j = shapeList[j];
            if(temp_i->getCircumference() > temp_j->getCircumference()){
                shapeList[i] = temp_j;
                shapeList[j] = temp_i;
            }
        }
    }
    for(int i = 0; i < count; i++){
        shapeList[i]->showInfo();
    }
    return 0;
}
