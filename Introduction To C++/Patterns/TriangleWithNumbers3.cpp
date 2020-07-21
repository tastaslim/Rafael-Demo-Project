#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int k=n-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j<=n-i+1)
			{
				cout<<k;
				k--;
			}
			else
				cout<<" ";
		}
		cout<<endl;
		k=n-i-1;
	}
	return 0;
}