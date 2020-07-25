#include <iostream>
using namespace std;
//There is a O(n^2) approach as Well Do try it. If you are
//Unable to do it. Find it on GeeksForGeeks.
//O(n) approach
int EquilibriumIndex(int *arr, int size)
{
    int ans = -1, sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int leftSum = 0;
    for (int i = 0; i < size; i++)
    {
        sum -= arr[i];
        if (sum == leftSum)
        {
            ans = i;
            break;
        }
        leftSum += arr[i];
    }
    return ans;
}
int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int ans = EquilibriumIndex(arr, size);
    cout << ans;
    return 0;
}
