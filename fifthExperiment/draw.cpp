#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
  int x;
  int y;
};

void disPlayMenu(){
  cout << "***************************" << endl;
  cout << "    1.Circle(圆)" << endl;
  cout << "    2.Rectangle(长方形) " << endl;
  cout << "    0.Exit(退出)" << endl;
  cout << "***************************" << endl;
  cout << "Please select the shape:";
}

void getTwoPoints( struct Point * startP, struct Point * endP){
    cout << "Please input the coordinate (x, y) of the start point:";
    cin >> startP->x >> startP->y;
    cout << "Please input the coordinate (x, y) of the end point:";
    cin >> endP->x >> endP->y;
}

void drawCircle(struct Point * startP, struct Point * endP){
    if(endP->x <= startP->x || endP->y <= startP->y) {
        cout << "error input!" << endl; 
    }
    else{
        if((endP->y - startP->y) != (endP->x - startP->x)){
          cout << "Not a circle,Select again" << endl;
        }
        else{
            cout << "Draw a circle at center (" << (endP->x + startP->x)/2 << ", ";
            cout << (endP->y + startP->y)/2 << ")" << " with radius ";
            cout << (endP->x - startP->x) / 2 << endl;          
        }
    }
}

void drawRectangle(struct Point * startP, struct Point * endP){
  if(endP->x <= startP->x || endP->y <= startP->y){
    cout << "error input!" << endl;
  }
  else{
    cout << "Draw a rectangle at topleft (" << startP->x << ", " << startP->y << "), ";
    cout << " whose width is " << endP->x - startP->x << " and height is " << endP->y - startP->y << endl;
  }
}

int main()
{
    int choice = 1;
    struct Point startP, endP;
    
    while( choice ){
        disPlayMenu();
        cin >> choice;

        switch ( choice)
        {
            case 1:
              getTwoPoints(&startP, &endP);
              drawCircle(&startP, &endP);break;
            
            case 2:
              getTwoPoints(&startP, &endP);
              drawRectangle(&startP, &endP);break;

            case 0:
              cout << "Good Bye!\n"; break;

            default:
              cout << "Not supported! Please select again!\n";
        }
    }

    return 0;
}
