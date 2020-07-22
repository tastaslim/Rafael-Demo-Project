#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void ReplacePi(char input[], int start)
{
    if (input[start + 1] == '\0')
    {
        return;
    }
    if (input[start] == 'p' && input[start + 1] == 'i')
    {
        for (int i = strlen(input); i > start + 1; i--)
        {
            input[i + 2] = input[i];
        }
        input[start] = '3';
        input[start + 1] = '.';
        input[start + 2] = '1';
        input[start + 3] = '4';
    }
    ReplacePi(input, start + 1);
}

void ReplacePi(char input[])
{
    ReplacePi(input, 0);
}
int main()
{
    char input[1000000];
    cin >> input;
    ReplacePi(input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        cout << input[i];
    }
    return 0;
}