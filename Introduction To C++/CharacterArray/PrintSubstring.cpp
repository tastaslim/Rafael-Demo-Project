#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void PrintSubstring(char input[]){
	for(int i=0;input[i]!='\0';i++){
		for(int j=i;input[j]!='\0';j++){
			for(int k=i;k<=j;k++){
				cout<<input[k];
			}
			cout<<endl;
		}
	}
}

int main() {
    char input[1000000];
    cin.getline(input,1000000);
    PrintSubstring(input);
}