#include<iostream>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 

    int start=0,end=n-1;
    for(int i=0;i<n;i++){
        if((i+1)%2==0){
            arr[end--]=i+1;
        }
        else{
            arr[start++]=i+1;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

  }
}


