
#include <iostream>
using namespace std;

int BS(int *arr, int start, int end, int x)
{
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
int BinarySearch(int *arr, int size, int x)
{
    int start = 0, end = 1;
    if (arr[start] == x)
        return start;
    int ans = -1;
    while (start <= end)
    {
        if (arr[end] >= x)
        {
            ans = BS(arr, start, end, x);
            return ans;
            break;
        }
        else if (arr[end] < x)
        {
            start = end;
            end = end * 2;
        }
    }
    return ans;
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
    int ans = BinarySearch(arr, n, x);
    cout << ans << endl;
    return 0;
}