
#ifndef class_hpp
#define class_hpp

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
class Shape{
public:
    virtual double getCircumference() = 0;
    virtual void showInfo() = 0;
    string getShape();
    bool operator > (Shape * shape2);
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

bool Shape::operator>(Shape *shape2){
    if(this->getCircumference() > shape2->getCircumference())
        return true;
    else
        return false;
}


Circle::Circle(double radius):Shape("圆"),radius(radius){
}

double Circle::getCircumference(){
    return 2 * 3.14 * radius;
}

void Circle::showInfo(){
    cout << "圆, 半径" << radius << ", 周长" << this->getCircumference() << endl;
}

Rectangle::Rectangle(double length, double width):length(length),width(width),Shape("长方形"){
}

double Rectangle::getCircumference(){
    return 2 * (length + width);
}

void Rectangle::showInfo(){
    cout << "长方形，长" << length ;
    cout << " 宽" << width << "，周长" << this->getCircumference() << endl;
}

RightTriangle::RightTriangle(double side1, double side2):side1(side1),side2(side2),Shape("三角形"){
}

double RightTriangle::getCircumference(){
    double side3 = sqrt((side1*side1) + (side2*side2));
    return side1 + side2 + side3;
}

void RightTriangle::showInfo(){
    cout << "三角形，直角边" << side1 << ", 直角边" << side2 ;
    cout << ", 周长" << this->getCircumference() << endl;
}
#endif /* class_hpp */

