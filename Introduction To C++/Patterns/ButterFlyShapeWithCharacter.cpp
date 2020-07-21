#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char k='A';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*n-1;j++){
		    if(j>n+1-i && j<n-1+i){
				cout<<" ";
			}
			else{
				cout<<k;
			}
			if(j<n){
					k++;
				}
				else{
					k--;
				}
		}
		cout<<endl;
		k='A';
	}
	return 0;
}