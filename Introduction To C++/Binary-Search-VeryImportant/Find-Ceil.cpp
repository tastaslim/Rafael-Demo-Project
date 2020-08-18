// If element exists our ceil would be that element only but if
// it does not exist in array ceil would be smallest integer which is larger
// than my given value to search
//{1,2,3,6,9,14,15} x=9 ----> Ceil===>9
//{1,2,3,6,9,14,15} x=4 -----> Ceil===>6
#include <iostream>
using namespace std;
int BinarySearchInNearlySorted(int *arr, int start, int end, int x)
{
    int ans = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else if (arr[mid] > x)
        {
            ans = arr[mid];
            end = mid - 1;
        }
        else
        {
            ans = arr[mid];
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