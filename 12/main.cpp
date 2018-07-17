#include <iostream>
#include <fstream>
#include <algorithm>
#include "class.h"
#include "Array.h"


using namespace std;

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using namespace std;

class FileNotFoundException:public runtime_error {
public:
    FileNotFoundException(const string& what_arg):runtime_error(what_arg){}
};

class Shape{
public:
    virtual double getCircumference() = 0;
    virtual void showInfo() = 0;
    virtual void setPrice(double newPrice) = 0;
    virtual double getPrice() = 0;
    virtual int getClassId() = 0;
    string getShape();
    bool operator > (Shape * s){
        if(this->getCircumference() > s->getCircumference())
            return true;
        else
            return false;
    }
    void setName(string newName){ shape = newName; }
    Shape(string);
private:
    string shape;
};

class Circle:public Shape{
public:
    Circle(double radius = 3):Shape("圆"),radius(radius){
    }
    virtual double getCircumference();
    void setPrice(double newPrice) { price=newPrice;}
    double getPrice() {return price;}
    double getRadius() {return radius;}
    virtual void showInfo();
    virtual int getClassId(){return classId;}
private:
    double radius;
    double price;
    int classId = 1;
};


class Rectangle:public Shape{
public:
    Rectangle(double length=3, double width=3):length(length),width(width),Shape("长方形"){
    }
    virtual double getCircumference();
    virtual void showInfo();
    void setPrice(double newPrice) { price = newPrice; }
    double getPrice() { return price; }
    double getLength() {return length;}
    double getWidth() {return width;}
    virtual int getClassId(){return classId;}
private:
    double length;
    double width;
    double price;
    int classId = 2;
};

class RightTriangle:public Shape{
public:
    RightTriangle(double side1=3, double side2=3):side1(side1),side2(side2),Shape("三角形"){
    }
    virtual double getCircumference();
    virtual void showInfo();
    void setPrice(double newPrice) { price = newPrice; }
    double getPrice() {return price;}
    double getSide1() {return side1;}
    double getSide2() {return side2;}
    virtual int getClassId(){return classId;}
private:
    double side1;
    double side2;
    double price;
    int classId = 3;
};

class Square:public Rectangle{
public:
    Square(double side=3):side(side),Rectangle(side,side){
    }
    virtual double getCircumference();
    virtual void showInfo();
    void setPrice(double newPrice) { price = newPrice; }
    double getPrice() {return price; }
    double getSide() {return side;}
    virtual int getClassId(){return classId;}
private:
    double side;
    double price;
    int classId = 4;
    
};

Shape::Shape(string shape):shape(shape){
}

string Shape::getShape(){
    return shape;
}

double Circle::getCircumference(){
    return 2 * 3.14 * radius;
}

void Circle::showInfo(){
    cout << "圆, 半径" << radius << ", 周长";
    cout  <<setiosflags(ios::fixed) << setprecision(2) << this->getCircumference();
    cout << "，价格" << this->getPrice() << endl;
}

double Rectangle::getCircumference(){
    return 2 * (length + width);
}

void Rectangle::showInfo(){
    cout << "长方形，长" << length ;
    cout << " 宽" << width << "，周长";
    cout <<setiosflags(ios::fixed) << setprecision(2) << this->getCircumference();
    cout << "，价格" << this->getPrice() << endl; 
}

double RightTriangle::getCircumference(){
    double side3 = sqrt((side1*side1) + (side2*side2));
    return side1 + side2 + side3;
}

void RightTriangle::showInfo(){
    cout << "三角形，直角边" << side1 << ", 直角边" << side2 ;
    cout << ", 周长" ;
    cout << setiosflags(ios::fixed) << setprecision(2)<< this->getCircumference();
    cout << ",价格" << this->getPrice() << endl;
}

double Square::getCircumference(){
    return 4 * side;
}

void Square::showInfo(){
    cout << "正方形，边长" << side << " 周长";
    cout  <<setiosflags(ios::fixed) << setprecision(2)<< this->getCircumference();
    cout << ",价格" << this->getPrice() << endl;
}


void Sort(Array<Shape*> &shapeList) {
    int i = 0, j = 0;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(shapeList[i]->getPrice() > shapeList[j]->getPrice()){
                swap(shapeList[i],shapeList[j]);           }
        }
    }
}

void readFile(Array<Shape*> &shapeList){
    ifstream infile;
    int classId = 0;
    string name = "";
    double price = 0;    
    infile.open("Shapes.txt",ios::in);
    if(!infile.is_open()){
        string message = "打开文件错误，请检查该目录是否存在Shapes.txt文件";
        throw FileNotFoundException(message);
    }
    for(int i = 0; i < 4; i++) {
        infile >> classId >> name >> price;
        if (classId == 1) {
            shapeList[i] = new Circle();
        }
        if (classId == 2) {
            shapeList[i] = new Rectangle();
        }
        if (classId == 3) {
            shapeList[i] = new RightTriangle();
        }
        if (classId == 4){
            shapeList[i] = new Square();
        }
        shapeList[i]->setName(name);
        shapeList[i]->setPrice(price);
    }
    Sort(shapeList);
    cout << "排序后输出..."  << endl;
    for(int i = 0; i < 4; i++){
        shapeList[i]->showInfo();
    }
    cout << endl;
    infile.close();
}

void writeFile(Array<Shape*> &shapeList){
    ofstream outfile1("Circle.dat", ios_base::out | ios_base::binary);
    ofstream outfile2("Rectangle.dat", ios_base::out | ios_base::binary);
    ofstream outfile3("RightTriangle.dat", ios_base::out | ios_base::binary);
    ofstream outfile4("Square.dat", ios_base::out | ios_base::binary);
    for(int i = 0; i < 4; i++){
        if(shapeList[i]->getClassId() == 1){
            Circle * ptr = dynamic_cast<Circle *>(shapeList[i]);
            outfile1.write(reinterpret_cast<char *>(ptr), sizeof(*ptr));
        }
        if(shapeList[i]->getClassId() == 2){
            Rectangle * ptr = dynamic_cast<Rectangle *>(shapeList[i]);
            outfile2.write(reinterpret_cast<char *>(ptr), sizeof(*ptr));
        }
        if(shapeList[i]->getClassId() == 3){
            RightTriangle * ptr = dynamic_cast<RightTriangle *>(shapeList[i]);
            outfile3.write(reinterpret_cast<char *>(ptr), sizeof(*ptr));
        }
        if(shapeList[i]->getClassId() == 4){
            Square * ptr = dynamic_cast<Square *>(shapeList[i]);
            outfile4.write(reinterpret_cast<char *>(ptr), sizeof(*ptr));
        }

    }
    outfile1.close();
    outfile2.close();
    outfile3.close();
    outfile4.close();
}

void readBinaryFile(Array<Shape*> shapeList){
    cout << "正在从文件中读取..."  << endl;

    ifstream CircleFile("Circle.dat", ios_base::in| ios_base::binary);
    Circle ptr1;
    CircleFile.read(reinterpret_cast<char*>(&ptr1),sizeof(ptr1));
    ptr1.showInfo();

    ifstream RectangleFile("Rectangle.dat", ios_base::in | ios_base::binary);
    Rectangle ptr2;
    RectangleFile.read(reinterpret_cast<char*>(&ptr2), sizeof(ptr2));
    ptr2.showInfo();

    ifstream RightTriangleFile("RightTriangle.dat", ios_base::in | ios_base::binary);
    RightTriangle  ptr3;
    RightTriangleFile.read(reinterpret_cast<char*>(&ptr3), sizeof(ptr3));
    ptr3.showInfo();

    ifstream SquareFile("Square.dat", ios_base::in | ios_base::binary);
    Square  ptr4;
    SquareFile.read(reinterpret_cast<char*>(&ptr4), sizeof(ptr4));
    ptr4.showInfo();

}

int main() {
    Array<Shape*> shapeList(4); 
    for(int i = 0; i < 4; i++){
        shapeList[i] = NULL;        //初始化为NULL
    }

    try{
    readFile(shapeList);            //读取文件
}   
    catch (FileNotFoundException &e){
        cout << e.what() << endl;   //打印异常信息
        return 0;
    }

    writeFile(shapeList);           //输出文件
    readBinaryFile(shapeList);      //读取二进制文件

    return 0;


}

