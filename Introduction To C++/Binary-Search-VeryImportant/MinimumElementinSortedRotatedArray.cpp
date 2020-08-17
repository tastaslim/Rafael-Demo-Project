// We are rotating by 1 postion only
// Sorted array is rotated and it is given as input to us. Now find
//How many times original sorted array is rotated to give our input array.

#include <bits/stdc++.h>
using namespace std;

int BS(vector<int> &nums)
{
    if (nums.size() == 0)
        return -1;

    int start = 0, end = nums.size() - 1;
    int min_index = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % (nums.size());
        int prev = (mid - 1) % (nums.size());
        if (nums.at(start) <= nums.at(end))
        {
            min_index = start;
            break;
        }
        if (nums.at(mid) <= nums.at(next) && nums.at(mid) <= nums.at(prev))
        {
            min_index = mid;
            break;
        }
        if (nums.at(mid) >= nums.at(start))
            start = mid + 1;
        else
            end = mid - 1;
    }
    return nums.at(min_index);
}

int main()
{
    //int arr[15] = {18 2 3 4 5 6 7 8 9 10 11 12 13};
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = BS(v);
    cout << ans << endl;
    return 0;
}