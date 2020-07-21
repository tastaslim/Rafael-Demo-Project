#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    char arr1[10000];
    cin >> arr1;
    char arr2[10000];
    cin >> arr2;
    unordered_map<char, int> mp;
    for (int i = 0; i < strlen(arr1); i++)
    {
        mp[arr1[i]] = 0;
    }
    if (strlen(arr1) != strlen(arr2))
    {
        cout << "Not Permuation of each other" << endl;
        return 0;
    }
    for (int i = 0; arr2[i] != '\0'; i++)
    {
        mp[arr1[i]]++;
        mp[arr2[i]]--;
    }
    bool m = true;
    for (int i = 0; i < strlen(arr1); i++)
    {
        if (mp[arr1[i]] != 0)
        {
            m = false;
        }
    }
    if (m)
    {
        cout << "Permuation of each other" << endl;
    }
    else
    {
        cout << "Not Permuation of each other" << endl;
    }
}