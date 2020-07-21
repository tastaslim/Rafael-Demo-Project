#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int k=1;
	for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=2*n-1;j++){
		    if(j>n+1-k && j<n-1+k){
				cout<<" ";
			}
			else{
				cout<<"*";
			}
		}
		if(i<n){
			k++;
		}
		else{
			k--;
		}
		cout<<endl;
	}
	return 0;
}