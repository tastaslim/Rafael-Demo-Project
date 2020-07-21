#include<iostream>
#include <algorithm>
using namespace std;
int main(){
    int size1,size2;
    cin>>size1>>size2;
    int *arr1=new int[size1];
    int *arr2=new int[size2];
    for(int i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<size2;i++)
    {
        cin>>arr2[i];
    }

    int ans[size2+size1];
    int i=0,j=0,k=0;
    while(i<size1 && j<size2)
    {
     if(arr1[i]>arr2[j])
         ans[k++]=arr2[j++];
     else
         ans[k++]=arr1[i++];
    }
    while(i<size1)
        ans[k++]=arr1[i++];
    while(j<size2)
        ans[k++]=arr2[j++];

    for(int i=0;i<size1+size2;i++){
	     cout<<ans[i]<<" ";
    }

    return 0;
}
