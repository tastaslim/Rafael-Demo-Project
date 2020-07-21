#include<iostream>
using namespace std;
#include <climits>
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=INT_MIN,sl=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>l){
            sl=l;
            l=arr[i];
        }
        else if(arr[i]>sl && arr[i]!=l){
            sl=arr[i];
        }
    }
        cout<<sl; 
}


