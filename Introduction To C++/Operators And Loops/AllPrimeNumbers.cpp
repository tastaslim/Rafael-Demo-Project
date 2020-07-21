#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool *check=new bool[n];
	for(int i=0;i<n;i++){
		check[i]=true;
	}
	check[0]=false,check[1]=false;

	for(int i=2;i*i<=n;i++){
		if(check[i]){
			for(int j=i*i;j<=n;j=j+i){
				check[j]=false;
			}
		}
	}

	for(int i=0;i<n;i++){
		if(check[i]){
			cout<<i<<" ";
		}
	}
	return 0;
}