#include <bits/stdc++.h>
using namespace std;
int binary(vector<int> &nums, int start, int end, int x)
{
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums.at(mid) > x)
            end = mid - 1;
        else if (nums.at(mid) < x)
            start = mid + 1;
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
}

int search(vector<int> &nums, int x)
{
    if (nums.size() == 0)
        return -1;
    int start = 0, end = nums.size() - 1, n = nums.size();
    int min_index = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1) % n;
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
    int k1 = binary(nums, 0, min_index - 1, x);
    int k2 = binary(nums, min_index, nums.size() - 1, x);
    if (k1 == -1 && k2 == -1)
        return -1;
    if (k1 != -1)
        return k1;
    return k2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int x;
    cin >> x;
    int ans = search(v, x);
    cout << ans << endl;
    return 0;
}