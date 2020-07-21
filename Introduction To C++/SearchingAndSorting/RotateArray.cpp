#include<bits/stdc++.h>
using namespace std;
void Rotate1(int arr[],int size) 
{
int i=0,j=size-1;
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    } 
}
void Rotate2(int arr[],int s,int e) 
{
int i=s,j=e-1;
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    } 
}

void Rotate(int arr[], int d, int size) 
{
Rotate1(arr,size);
Rotate2(arr,0,size-d);
Rotate2(arr,size-d,size);
}	

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // Enter by how many length you want array to rotate
    int d;
    cin>>d;
    Rotate(arr,d,n);

    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
    }
    return 0;
}