#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool m=true,t=true;
	int count=0;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
        if(arr[i]==arr[i-1]){
            t=false;
        }
	}
	for(int i=0;i<n;i++){
		if(arr[i]>arr[i+1]){
			count++;
			m=false;
		}
		else{
			break;
		}
	}
    bool k=true;
	for(int i=count;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			k=false;
		}
	}
	if((m || count==n || k) & t){
		cout<<"true";
	}
	else
		cout<<"false";

	return 0;
}