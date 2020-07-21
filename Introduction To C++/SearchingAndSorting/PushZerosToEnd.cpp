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
 
   // Requires an Extra space Space Complexity: O(n).
    
    /*int start=0,end=n-1;
    int b[n];
    for(int i=0;i<n;i++){
    	if(arr[i]==0){
    		b[end--]=arr[i];
    	}
    	else{
    		b[start++]=arr[i];
    	}
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
   */


    // No extra Space but takes 2 iteration on array

   /* int k=0;

    for(int i=0;i<n;i++){   //Iteration 1
        if(arr[i]!=0){
            arr[k++]=arr[i];
        }
    }

    for(int i=k;i<n;i++){  //Iteration 2
        arr[i]=0;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    */


    // No extra Space and 1 Iteration only.
    //This is very Important Method. Do remember it because with the help of this we can perform operations 
    //like even odd, +ve -ve, 0 1 and many more.
    

    int k=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[k]);
            k++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}