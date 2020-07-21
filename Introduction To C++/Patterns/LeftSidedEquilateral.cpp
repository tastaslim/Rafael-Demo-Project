#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int k=1;
	for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=k;j++){
			cout<<"*";
			}
		if(i<n){
			k++;
		}
		else{
			k--;
		}
			cout<<endl;
		}

}