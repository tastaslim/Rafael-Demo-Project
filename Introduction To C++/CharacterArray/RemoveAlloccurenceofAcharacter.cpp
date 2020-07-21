#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    char arr[100000];
    cin >> arr;
    int k = 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] != 'x')
        {
            arr[k++] = arr[i];
        }
    }
    arr[k] = '\0';
    cout << arr;
}