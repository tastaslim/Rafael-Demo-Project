#include<iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //Extra space O(n)
    /*
    int b[n],start=0,end=n-1;
    for(int i=0;i<n;i++){
    	b[i]=1;
    }

    for(int i=0;i<n;i++){
    	if(arr[i]==0){
    		b[start]=arr[i];
    		start++;
    	}
    	else if(arr[i]==2){
    		b[end]=arr[i];
    		end--;
    	}
    }

    for(int i=0;i<n;i++){
    	cout<<b[i]<<" ";
    }
    */

    //Without any Extra Space and One Scan Only.
    //But you see we are performing many unneccesary swaps

   /* int start=0,end=n-1,mid=0;

    while(start<=end){
        switch(arr[mid]){
            case 0:
              swap(arr[mid],arr[start]);
              mid++,start++;
              break;

            case 1:
              swap(arr[mid],arr[end]);
              end--;
              break;

            case 2:
              mid++;
              break;

        }
    }*/



    //Without any Extra Space and Two Scans Only.
    //But No swaps
    int count0=0, count1=0, count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0)
            count0++;
        else if(arr[i]==1)
            count1++;
        else
            count2++;
    }
    int k=0;
    while(count0>0){
        arr[k++]=0;
        count0--;
    }


    while(count1>0){
        arr[k++]=1;
        count1--;
    }

    while(count2>0){
        arr[k++]=2;
        count2--;
    }
     
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}