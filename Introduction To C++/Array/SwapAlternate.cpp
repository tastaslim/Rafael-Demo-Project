#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i=i+2){
        if(i+1<n){
            a[i]=a[i]^a[i+1];
            a[i+1]=a[i]^a[i+1];
            a[i]=a[i]^a[i+1];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}


