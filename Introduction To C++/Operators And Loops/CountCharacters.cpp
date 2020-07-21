#include<iostream>
using namespace std;
int main(){
	char arr[100000];
	int count1=0,count2=0,count3=0;
	cin.getline(arr,100000);
	for(int i=0;arr[i]!='\0';i++){
		if(arr[i]>=0+'0' && arr[i]<=9+'0'){
			count1++;
		}
		else if((arr[i]>='a' && arr[i]<='z') || (arr[i]>='A' && arr[i]<='Z')){
			count2++;
		}
		else
		{
			count3++;
		}
	}
	cout<<count1<<" "<<count2<<" "<<count3;
	return 0;
}