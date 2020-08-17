#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        // Inserts element at last
        v.push_back(a);
    }

    for (int i = 0; i < v.size(); i++)
    {
        // Prints value at i index
        cout << v.at(i) << " ";
    }

    // Sorting vector
    sort(v.begin(), v.end());

    // Reverse Sorting
    sort(v.rbegin(), v.rend());

    // Popping element from
    v.pop_back();

    // Dynamic vector

    vector<int> *v1 = new vector<int>();
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        // Inserts element at last
        v1->push_back(a);
        //Printing element
        cout << v1->at(i) << " ";
    }

    sort(v1->begin(), v1->begin());

    return 0;
}