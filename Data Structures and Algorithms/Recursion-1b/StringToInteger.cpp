#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void StringToInteger(char input[], int start, int &k)
{
    if (input[start] == '\0')
    {
        return;
    }
    char c = input[start];
    k = k * 10 + (input[start] - '0');
    StringToInteger(input, start + 1, k);
}

int StringToInteger(char input[])
{
    int k = 0;
    StringToInteger(input, 0, k);
    return k;
}
int main()
{
    char input[1000000];
    cin >> input;
    int n = StringToInteger(input);
    cout << n;
    return 0;
}
