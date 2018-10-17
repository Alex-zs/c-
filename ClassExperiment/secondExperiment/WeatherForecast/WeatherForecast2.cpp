#include<iostream>
#include<iomanip>
using namespace std;

void displatTemps(int temp[], int n){
    int foo = 0;
    int bar = 0;
    int min = temp[0];
    cout << "显示柱状图如下：" << endl;

    for(foo = 0; foo < n; foo++){
        if(min > temp[foo]){
            min = temp[foo];
        }
    }
    if(min > 0){
        for(foo = 0; foo < n; foo++){
            cout << right << setw(4) << temp[foo];
            cout << "  ";
            for(bar = 0; bar < temp[foo]; bar++){
                cout<<"*";
            }
             cout << endl;
        }
    }
    if(min < 0){
        min = - min;
        for(foo = 0; foo < n; foo++){
            cout << right << setw(4) << temp[foo];
            cout << "  ";

            if(temp[foo] >= 0){
                for(bar = 0; bar < min; bar ++){
                    cout<<" ";
                }
                cout << "|";
                for( bar = 0; bar < temp[foo]; bar ++){
                    cout << "*";
                }
            }
            else{
                int t = - temp[foo];
                for(bar = 0; bar < min - t; bar++){
                    cout << " ";
                }
                for(bar = 0; bar < t; bar ++){
                    cout << "*";
                }
                cout << "|";
            }
            cout << endl;
        }
    }
}

void inputTemps(int temp[], int n){
    int foo = 0;
    cout << "Please input the tempratures:"<<endl;
    for(foo = 0; foo < n; foo++){
        cin >> temp[foo];
    }
    cout << endl;
}
void displayFlat(int temp[], int n){
    int length = 1;
    int bar = 1;
    int number = temp[0];
    cout << endl;
    for(int foo = 0; foo < n; foo++){
        if(temp[foo] == temp[foo + 1]){
            bar ++ ;
        }
        if(temp[foo] != temp[foo + 1]){
            if(length < bar){
                number = temp[foo];
                length = bar;
            }
            bar = 1;
        }
    }
    if(length < bar){
        length = bar;
    }
    if(length !=1)
    {
        cout << "出现次数最多的是" << number <<"," << "出现了" << length << "次。"<<endl;
    }
    else{
        cout << "没有次数最多"<<endl;
    }

}
int main(){
    int temps[15];
    
    inputTemps(temps, 15);
    displatTemps(temps, 15);
    displayFlat(temps, 15);
    return 0;
}

