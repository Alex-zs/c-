#include <iostream>
#include <string>
using namespace std;

bool isObject(string str, int n) {
    int foo = 0;
    string str_s;

    if(n == 3) {
        for(foo = 0; foo < 4; foo++) {
            str_s = str_s + str[foo];
        }
        if(str_s == "EWWW" || str_s == "WEWW" || str_s == "WWEW" || str_s == "WWWE" || str_s == "WWWB") {
            return true;
        }
        else {
            return false;
        }
    }

    if(n == 4) {
        for(foo = 0; foo < 5; foo++) {
            str_s = str_s + str[foo];
        }
        if(str_s == "EWWWW" || str_s == "WEWWW" || str_s == "WWEWW" || str_s == "WWWEW" || str_s == "WWWWE" || str_s == "WWWWB") {
            return true;
        }
        else {
            return false;
        }
    }

    return false;
}

void object(string  str, int n) {
    int address = 0;
    int left = 0;
    int right = 0;
    string sort[6];
    int count = 0;
    address = str.find("E");
    left = address - 0;
    right = 2*n - address;
    left = left > 3 ? 3 :left;
    right = right > 3 ? 3:right;
    
    for(int bar = 0; bar < left; bar++) {
        string obs = str;
        char temp = obs[address];
        obs[address] = obs[address - bar - 1];
        obs[address - bar - 1] = temp ;
        sort[count] = obs;
        count++;
    }
    for(int bar = 0; bar < right; bar++) {
        string obs = str;
        char temp = obs[address];
        obs[address] = obs[address + bar + 1];
        obs[address + bar + 1] = temp;
        sort[count] = obs;
        count++;
    }
    count = count -1;
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count; j++) {
            if(sort[j] > sort[j+1]) {
                string tem = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = tem;
            }
        }
    }
    for(int i = 0; i < count + 1; i++) {
        cout << sort[i] << endl;
    }

}

int main() {
    int number[10];
    int count;
    string str[10];
    cin >> count;
    for(int i = 0; i < count; i++) {
        cin >> number[i];
        cin >> str[i];
    }
    for(int i = 0; i < count; i++) {
        cout << "结果_" << i+1 << endl;
        if(isObject(str[i], number[i]) == true) {
            cout << "目标格局" << endl;
        }
        else {
            object(str[i], number[i]);
        }
    }
}




