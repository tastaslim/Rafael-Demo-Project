#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char k='A';
	//int k=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*n-1;j++){
			if(j>=n+1-i && j<=n-1+i){
				cout<<k;
				if(j<n){
				  k++;	 
				}
				else{
					k--;	
				}
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
		k='A';
		//k=1;
	}
	return 0;
}