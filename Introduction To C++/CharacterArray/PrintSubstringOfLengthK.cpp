#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void PrintSubstring(char input[],int k){
	for(int i=0;input[i]!='\0';i++){
		for(int j=i;input[j]!='\0';j++){
			for(int k=i;k<=j;k++){
				if(j-i==k-1)
				  cout<<input[k];
			}
			if(j-i==k-1)
			cout<<endl;
		}
	}
}

int main() {
    char input[1000000];
    cin.getline(input,1000000);
    int k;
    cin>>k;
    PrintSubstring(input,k);
}