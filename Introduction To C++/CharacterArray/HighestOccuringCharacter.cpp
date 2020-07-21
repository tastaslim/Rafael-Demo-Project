#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;
int main()
{
    char arr[100000];
    cin >> arr;
    unordered_map<char, int> mp;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        mp[arr[i]]++;
    }
    int k = 0;
    char ans;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        int s = mp[arr[i]];
        char c = arr[i];
        if (s > k)
        {
            k = s;
            ans = c;
        }
    }
    cout << ans;
}