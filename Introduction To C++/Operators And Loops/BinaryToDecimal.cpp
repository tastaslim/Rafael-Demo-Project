#include<iostream>
using namespace std;
int power(int a, int b){
	if(b==0)
		return 1;
	int rec=power(a,b-1);
	return a*rec;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i=0,sum=0;
	while(n>0){
		int rem=n%10;
		int temp=power(2,i);
		sum+=rem*temp;
		n=n/10;
		i=i+1;
	}
	cout<<sum<<endl;
	return 0;
}