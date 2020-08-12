#include <iostream>
using namespace std;
int BS(int *arr, int size, int x)
{
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
            return mid;
        }
    }
    return -1;
}
int main()
{
    int arr[7] = {1, 2, 3, 4, 6, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int valuetofind;
    cin >> valuetofind;
    int ans = BS(arr, size, valuetofind);
    cout << ans << endl;
    return 0;
}