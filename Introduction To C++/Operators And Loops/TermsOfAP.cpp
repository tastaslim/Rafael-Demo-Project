#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i=1;
	int count=0;
	while(count<n){
		int sum=3*i+2;
		count++;
		if(sum%4!=0){
			cout<<sum<<endl;
		}
		else{
			count=count-1;
		}
		i++;
	}
	return 0;
}