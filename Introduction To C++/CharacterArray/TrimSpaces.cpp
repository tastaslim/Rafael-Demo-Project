#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
// With Extra Space

/*void TrimSpace(char input[]) {
    char a[100000];
    int k=0;
    for(int i=0;input[i]!='\0';i++)
    {
    if(input[i]!=' ')
        input[k++]=input[i];
    }
    input[k]='\0';
}
*/

//Without any Extra Space

void TrimSpace(char input[]){
    int k=0;
    for(int i=0;input[i]!='\0'; i++){
        if(input[i]!=' '){
            input[k++]=input[i];
        }
    }
    input[k]='\0';
}

int main() {
    char input[1000000];
    cin.getline(input,1000000);
    TrimSpace(input);
    cout << input << endl;
}
