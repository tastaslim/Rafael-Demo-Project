#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int value;
    cin>>value;
    bool m=false;
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==value){
            m=true;
            index=i;
        }
    }

    if(m){
        cout<<value<<" found at index: "<<index;
    }
    else{
        cout<<"Value not found in array";
    }
    return 0;
    
}


