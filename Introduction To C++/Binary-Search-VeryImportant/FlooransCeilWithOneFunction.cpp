#include <bits/stdc++.h>
using namespace std;

void BS(int *arr, int size, int x)
{
    int ans = -1;
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            break;
        }
    }
    if (ans == -1)
    {
        // cout << "Ceil:" << arr[start] << endl
        //      << "Floor:" << arr[end] << endl;
        int res = min(abs(arr[start] - x), abs(arr[end] - x));
        if (abs(arr[start] - x) > abs(arr[end] - x))
        {
            ans = end;
        }
        else
        {
            ans = start;
        }
        cout << arr[ans] << endl;
    }
    else
    {
        // Floor and Ceil would be same.
        cout << "Element found: " << arr[ans] << endl;
    }
}

int main()
{
    //int arr[15] = {1 2 3 4 5 6 7 8 9 10 11 12 13};
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    BS(arr, n, x);
    return 0;
}