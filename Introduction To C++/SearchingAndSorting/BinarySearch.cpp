#include<iostream>
using namespace std;

int BinarySearch(int *arr, int n, int start, int end, int value){
	if(start>end){
		return -1;
	}

	int mid=(start+end)/2;

	if(arr[mid]>value){
		return BinarySearch(arr,n,start,mid-1,value);
	}
	else if(arr[mid]<value){
		return BinarySearch(arr,n,mid+1,end,value);
	}
	else{
		return mid;
	}
}

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
    // Using recursion
    int ans=BinarySearch(arr,n,0,n-1,value);
    if(ans!=-1){
    	cout<<"Value found at Index: "<<ans<<endl;
    }
    else{
    	cout<<"Value not found in Array"<<endl;
    }

    // Iterative Approach

    
    /*int start=0,end=n-1;
    while(start<end){
    	int mid=(start+end)/2;
    	if(arr[mid]>value){
    		end=mid-1;
    	}
    	else if(arr[mid]<value){
    		start=mid+1;
    	}
    	else{
    		cout<<"Value found at Index: "<<mid<<endl;
    		return 0;
    	}
    }
    cout<<"Value not found in Array"<<endl;
    */
    return 0;
}