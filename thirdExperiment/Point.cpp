#include <iostream>
using namespace std;

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
    private:
        int x;
        int y;
};

int  main() {
    int x, y;
    cout << "Please input a point: ";
    cin >> x >> y;
    Point p1(x,y);
    cout << "Point p1: ";
    p1.print();
    cout << endl;
    Point p2(x * 2, y * 2);
    cout << "Point p2: ";
    p2.print();
    cout << endl;
    p1.moveRight(10);
    cout << "After moving right, p1: ";
    p1.print();
    cout << endl;
    p2.moveDown(-10);
    cout << "After moving down, p2: ";
    p2.print();
    cout << endl;
    return 0;
}
