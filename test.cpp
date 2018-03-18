#include<iostream>
using namespace std;
void elevator(int arr[100][100]){
    int rows=0,j=0,sum=0;
    for(;arr[rows][1]!=0;rows++){
        for(j=0;arr[rows][j+1]!=0;j++){
            if(arr[rows][j]<arr[rows][j+1]){
                sum = sum + 6*(arr[rows][j+1]-arr[rows][j])+5;
            }
            else{
                sum = sum + 4*(arr[rows][j]-arr[rows][j+1])+5;
            }
        }
            cout<<sum;
            sum = 0;
            cout<<"(";
            for(j=0;arr[rows][j+1]!=0;j++){
                if(arr[rows][j]<arr[rows][j+1]){
                    cout<<"6*"<<arr[rows][j+1]-arr[rows][j]<<"+5";
                }
                else{
                    cout<<"4*"<<arr[rows][j]-arr[rows][j+1]<<"+5";
                }
                if(arr[rows][j+2]!=0){
                    cout<<"+";
                }
            }
            cout<<")"<<endl;
    }
}
int main(){
    void elevator(int arr[100][100]);
    int rows=0,arr[100][100]={{0}},n,i;
    for(;(cin>>n)&&n!=0;rows++){
        for(i=0;i<n;i++){
            cin>>arr[rows][i+1];
        }
    }
    elevator(arr);
    return 0;
}

