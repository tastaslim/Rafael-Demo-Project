#include <bits/stdc++.h>
using namespace std;
void Leaders(int *arr, int len)
{
    //With Extra Space

    // int k = 0, max = INT_MIN;
    // int b[len] = {0};
    // for (int i = len - 1; i >= 0; i--)
    // {
    //     if (arr[i] >= max)
    //     {
    //         max = arr[i];
    //         b[k++] = arr[i];
    //     }
    // }
    // for (int i = k - 1; i >= 0; i--)
    // {
    //     cout << b[i] << " ";
    // }

    //Without Extra Space
    int k = len - 1, max = INT_MIN;
    int b[len] = {0};
    for (int i = len - 1; i >= 0; i--)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
            arr[k--] = arr[i];
        }
    }
    for (int i = k + 1; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int len;
    cin >> len;
    int *arr = new int[len + 1];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    Leaders(arr, len);
}
