#include <iostream>
#include "Array.h"
using namespace std;

template <class T>
class MyStack{
public:
    MyStack(int count);
    void push(const T& element);
    void pop();
    T top();
    bool empty();
private:
    Array<T> array;
    int count;            
    int number;           
    
};

template<class T>
MyStack<T>::MyStack(int newCount):count(newCount),number(0){
    array.resize(count);      
}

template<class T>
void MyStack<T>::push(const T & element){
    array[number++] = element;
}

template<class T>
void MyStack<T>::pop(){
    number--;
}

template<class T>
T MyStack<T>::top(){
    return array[number-1];
}

template<class T>
bool MyStack<T>::empty(){
    return number == 0;
}


double calculate(char* arr, int count){
    MyStack<double> stack(count);
    double foo = 0, bar = 0;
    for(int i = 0; i < count; i++){
        char temp = arr[i];
        switch(temp){
            case '*':
                foo = stack.top();
                stack.pop();
                bar = stack.top();
                stack.pop();
                stack.push(foo * bar);
                break;
            case '/':
                foo = stack.top();
                stack.pop();
                bar = stack.top();
                stack.pop();
                stack.push(bar / foo);
                break;
            case '+':
                foo = stack.top();
                stack.pop();
                bar = stack.top();
                stack.pop();
                stack.push(bar + foo);
                break;
            case '-':
                foo = stack.top();
                stack.pop();
                bar = stack.top();
                stack.pop();
                stack.push(bar - foo);
                break;
            default:
                stack.push(arr[i]-'0');
                break;

        }
    }
    return stack.top();
}

int main() {
    char expression_1[] = {'8','2','-'};
    char expression_2[] = {'8','2','3','*','-'};
    char expression_3[] = {'8','2','-','3','*'};
    char expression_4[] = {'8','2','/','3','/'};
    
    cout << "expression_1 = " << calculate(expression_1, 3) << endl;
    cout << "expression_2 = " << calculate(expression_2, 5) << endl;
    cout << "expression_3 = " << calculate(expression_3, 5) << endl;
    cout << "expression_4 = " << calculate(expression_4, 5) << endl;

    return 0;
    
}
