#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
T compare(T* array, int n){
    T max = array[0];
    for(int i = 0; i < n; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

class Point {
    public:
        Point (int xx = 0, int yy = 0){
            x = xx;
            y = yy;
        }
        void setX (int xx) {
            x = xx;
        }
        int getX() {
            return x;
        }
        void setY(int yy) {
            y = yy; 
        }
        int getY() {
            return y;
        }
        void print() {
            cout << "(" << x << ", " << y << ")" << endl;
        }
        void moveRight(int offset) {
            x = x + offset;
        }
        void moveDown(int offset) {
            y = y + offset;
        }
        double distanceTo(){
            return sqrt(x * x + y * y);
        }
        bool operator > (Point &p){
            if(this->distanceTo() > p.distanceTo())
                return true;
            else
                return false;
        }
    private:
        int x;
        int y;
};

int  main() {
    Point points[3] = {
        Point(9,2),
        Point(2,3),
        Point(1,3),
    };
    Point max = compare(points,3);
    max.print();
    return 0;
}
