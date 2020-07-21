#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	char arr[1000000];
	cin>>arr;
	int i=0,j=strlen(arr)-1;
	bool m=true;
	while(i<j){
		if(arr[i++]!=arr[j--])
			m=false;
	}
	if(m){
		cout<<"Palindrome"<<endl;
	}
	else{
		cout<<"Not Palindrome"<<endl;
	}
	return 0;
}