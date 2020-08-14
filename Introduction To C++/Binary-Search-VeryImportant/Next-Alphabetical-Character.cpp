#include <bits/stdc++.h>
using namespace std;
int BinarySearchInNearlySorted(char *arr, int size, char x)
{
    int ans = -1;
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] <= x)
        {
            start = mid + 1;
            ans = start % size;
        }
        else if (arr[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            ans = start % size;
            break;
        }
    }
    if (ans == -1)
        ans = 0;

    return ans;
}
int main()
{
    //int arr[15] = {18 2 3 4 5 6 7 8 9 10 11 12 13};
    int n;
    cin >> n;
    char *arr = new char[n];
    cin >> arr;
    char x;
    cin >> x;
    int ans = BinarySearchInNearlySorted(arr, n, x);
    cout << arr[ans] << endl;
    return 0;
}