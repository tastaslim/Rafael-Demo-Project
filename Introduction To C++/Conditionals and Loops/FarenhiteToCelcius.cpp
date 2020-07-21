#include<iostream>
using namespace std;
int main(){
	int start,end,step;
	cin>>start>>end>>step;
	cout<<"Farenhite"<<" "<<"Celcius"<<endl;
	for(int i=start;i<=end;i+=step){
		int k=((i-32)*5)/9;
		cout<<"  "<<i<<"        "<<k<<endl;
	}
	return 0;
}