#include<iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        int value=arr[i];
        int hole=i;
        while(hole>0 && arr[hole-1]>value){
            swap(arr[hole-1],arr[hole]);
            hole--;
        }
    }

    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
    }
    return 0;
}