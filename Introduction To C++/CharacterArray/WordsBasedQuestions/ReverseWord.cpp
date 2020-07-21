#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
void ReverseWord(char input[]){
	int i=0,j=strlen(input)-1;
	while(i<j){
		swap(input[i++],input[j--]);
	}
}

int main() {
    char input[1000000];
    cin.getline(input,1000000);
    ReverseWord(input);
    cout << input << endl;
}