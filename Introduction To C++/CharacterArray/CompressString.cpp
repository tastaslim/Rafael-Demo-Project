#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;
int main()
{
    char arr[100000];
    cin >> arr;

    // With an Extra Space O(n)
    /* char extra[100000];
    int k = 0, count = 1;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
        }
        else if (count == 1)
        {
            extra[k++] = arr[i];
        }
        else
        {
            extra[k++] = arr[i];
            extra[k++] = count + '0';
            count = 1;
        }
    }
    extra[k] = '\0';
    for (int i = 0; i < k; i++)
    {
        cout << extra[i];
    }*/

    //  Without any Extra Space

    int k = 0, count = 1;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
        }
        else if (count == 1)
        {
            arr[k++] = arr[i];
        }
        else
        {
            arr[k++] = arr[i];
            arr[k++] = count + '0';
            count = 1;
        }
    }
    arr[k] = '\0';
    for (int i = 0; i < k; i++)
    {
        cout << arr[i];
    }

    return 0;
}