#include<iostream>
#include<string>
using namespace std;
int power(int a, int b){
	if(b==0)
		return 1;
	int rec=power(a,b-1);
	return a*rec;
}
int main(int argc, char const *argv[])
{
	int n,sum=0,i=0;
	cin>>n;
	while(n>0){
		int rem=n%2;
		sum=sum+rem*power(10,i);
		n=n/2;
		i=i+1;
	}
	cout<<sum<<endl;
	return 0;
}

//Works for smaller number only
//For larger take a character array