#include <iostream>
#include "class.h"
#include "Array.h"

using namespace std;

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
            Circle *circle = new Circle(radius);
            if(count == shapeList.getSize()){
                shapeList.resize(count * 2);
            }
            shapeList[count] = circle;
            count++;
        }
        if (shape == 2) {
            double length;
            double width;
            cout << "Please input the length and the width:";
            cin >> length >> width;
            Rectangle * rectangle = new Rectangle(length, width);
            if(count == shapeList.getSize()){
                shapeList.resize(count * 2);
            }
            shapeList[count] = rectangle;
            count++;
        }
        if (shape == 3) {
            double side1;
            double side2;
            cout << "Please input the side and another side:";
            cin >> side1 >> side2;
            RightTriangle *rightTriangle = new RightTriangle(side1, side2);
            if(count == shapeList.getSize()){
                shapeList.resize(count * 2);
            }
            shapeList[count] = rightTriangle;
            count++;
        }
    }
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            if(shapeList[i] < shapeList[j]){
                Shape * temp = shapeList[i];
                shapeList[i] = shapeList[j];
                shapeList[j] = temp;
            }
        }
    }
    for(int i = 0; i < count; i++){
        shapeList[i]->showInfo();
    }
    return 0;
}
