#include<iostream>
using namespace std;
int main(){
	char c;
	cin>>c;
	if(c>='a' && c<='z'){
		cout<<"Lower Case";
	}
	else if(c>='A' && c<='Z'){
		cout<<"Upper Case";
	}
	else{
		cout<<"Some special chracter";
	}
	return 0;
}