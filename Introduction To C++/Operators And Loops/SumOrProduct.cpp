#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int choice;
	cin>>choice;
	int sum=0,product=1;
	switch(choice){
		case 1:
		    for(int i=1;i<=n;i++){
		    	sum+=i;
		    }
		    cout<<sum<<endl;
		    break;
		case 2:
		    for(int i=1;i<=n;i++){
		    	product*=i;
		    }
		    cout<<product<<endl;
		    break;
		default:
		   cout<<"Invalid Selection";

	}
	return 0;
}