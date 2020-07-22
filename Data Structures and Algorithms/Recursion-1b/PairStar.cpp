#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void PlaceStar(char input[], int start)
{
    if (input[start + 1] == '\0')
    {
        return;
    }
    if (input[start] == input[start + 1])
    {
        for (int i = strlen(input); i >= start + 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[start + 1] = '*';
    }
    PlaceStar(input, start + 1);
}

void PlaceStar(char input[])
{
    PlaceStar(input, 0);
}
int main()
{
    char input[1000000];
    cin >> input;
    PlaceStar(input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        cout << input[i];
    }
    return 0;
}