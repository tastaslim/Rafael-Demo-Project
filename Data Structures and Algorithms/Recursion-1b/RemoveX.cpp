#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void RemoveX(char input[], int start)
{
    if (input[start] == '\0')
    {
        return;
    }
    if (input[start] == 'x')
    {
        for (int i = start + 1; i <= strlen(input); i++)
        {
            input[i - 1] = input[i];
        }
        start = start - 1;
    }
    RemoveX(input, start + 1);
}

void RemoveX(char input[])
{
    RemoveX(input, 0);
}
int main()
{
    char input[1000000];
    cin >> input;
    RemoveX(input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        cout << input[i];
    }
    return 0;
}