// Our element can at mid or mid-1 or mid+1.
// these 3 elements would be cause of array not sorted if we move by
// mid+2 or mid-2. Ultimately we will get rest array sorted.
#include <iostream>
using namespace std;
int BinarySearchInNearlySorted(int *arr, int start, int end, int x)
{
    int ans = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] < x && arr[mid + 1] < x && arr[mid - 1] < x)
        {
            start = mid + 2;
        }
        else if (arr[mid] > x && arr[mid + 1] > x && arr[mid - 1] > x)
        {
            end = mid - 2;
        }
        else
        {
            if (arr[mid] == x)
                ans = mid;
            else if (arr[mid + 1] == x)
                ans = mid + 1;
            else if (arr[mid - 1] == x)
                ans = mid - 1;
            break;
        }
    }
    return ans;
}
int main()
{
    //int arr[15] = {18 2 3 4 5 6 7 8 9 10 11 12 13};
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int ans = BinarySearchInNearlySorted(arr, 0, n - 1, x);
    cout << ans << endl;
    return 0;
}