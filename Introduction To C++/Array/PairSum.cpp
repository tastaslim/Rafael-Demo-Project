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
	int sum;
	cin>>sum;


	/* O(n^2) approach*/

	/*for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==sum){
				cout<<min(arr[i],arr[j])<<" "<<max(arr[i],arr[j])<<endl;
			}
		}
	}
	*/

	/* O(nlogn) approach*/

    /*
    int count1=1,count2=1;
	sort(arr,arr+n);
	int i=0,j=n-1;
	while(i<j){
		if(arr[i]+arr[j]>sum){
			j--;
		}
		else if(arr[i]+arr[j]<sum){
			i++;
		}
		else{
			int r=i+1,s=j-1;
			while(arr[i]==arr[r]){
				count1++;
				r++;
			}
			while(arr[j]==arr[s]){
				count2++;
				s--;
			}

			for(int l=0;l<count1*count2;l++){
				cout<<min(arr[i],arr[j])<<" "<<max(arr[i],arr[j])<<endl;
			}
			i=r,j=s;
			count1=1;
			count2=1;
		}
	}
	*/

	/*O(n) approach ----> Best approach*/
	   unordered_map<int,int> mp;
	   for(int i=0;i<n;i++){
	   	mp[arr[i]]++;
	   }

	   for(int i=0;i<n;i++){
	   	int k=arr[i];
	   	int l=sum-arr[i];
	   	 for(int j=0;j<mp[k]*mp[l];j++){
			cout<<min(k,l)<<" "<<max(k,l)<<endl;
	   	 }
	   	 mp[k]=0,mp[l]=0;
	   }
	return 0;
}