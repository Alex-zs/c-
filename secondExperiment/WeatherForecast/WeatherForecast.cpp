#include <iostream>
#include <iomanip>
using namespace std;

void inputTemps(int temp[], int n){
    int foo = 0;

    cout << "Please input the tempratures:"<<endl;
    for(foo = 0; foo < n; foo++){
        cin >> temp[foo];
    }
    cout << endl;
}

void displatTemps(int temp[], int n){
    int foo = 0;
    
    cout << "显示柱状图如下：" << endl;
    for(foo = 0; foo < n; foo++){
        cout << left <<setw(5) << foo + 1;
        for(int bar = 0; bar < temp[foo]; bar++){
            cout<<"*";
        }
        cout << endl;
    }
}

void displayPeaks(int temp[], int n){
    int foo = 1;

    cout <<endl << "显示峰值如下："<<endl;
    for(foo = 1; foo < n - 1; foo++){
        if(temp[foo] > temp[foo -1] && temp[foo] > temp[foo +1]){
            cout << "Max at day " << foo + 1 <<" is "<<temp[foo]<<endl;
        }
    }
}

void displayFlat(int temp[], int n){
    int length = 1;
    int bar = 1;
    cout << endl << "显示崮的长度如下："<<endl;
    for(int foo = 0; foo < n; foo++){
        if(temp[foo] == temp[foo + 1]){
            bar ++ ;
        }
        if(temp[foo] != temp[foo + 1]){
            if(length < bar){
                length = bar;
            }
            bar = 1;
        }
    }
    if(length < bar){
        length = bar;
    }
    cout << "The length of longest flat is " << length <<endl;

}

int main(){
    int temps[15];

    inputTemps(temps, 15);
    displatTemps(temps, 15);
    displayPeaks(temps, 15);
    displayFlat(temps, 15);
    return 0;
}
        
