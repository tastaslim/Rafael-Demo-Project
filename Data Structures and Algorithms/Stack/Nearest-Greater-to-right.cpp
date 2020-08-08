// Another name of question is next largest element to right

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
// O(n^2) approach using brute force

/*vector<int> NextLargestToRight(int *arr, int n)
{
    vector<int> v;
    for (int i=0;i<n;i++)
    {
        bool m=true;
        for (int j=i+1;j<n;j++)
        {
            if (arr[j]>arr[i])
            {
                v.push_back(arr[j]);
                //cout<<arr[j]<<" ";
                m=false;
                break;
            }
        }
        if (m) {
            v.push_back(-1);
            //cout<<-1<<" ";
        }
    }
    return v;
}
*/

// Using stack and better one
vector<int> NextLargestToRight(int *arr, int n)
{
    vector<int> v;
    stack<int> s;
    for (int i=n-1;i>=0;i--)
    {
        if (s.empty())
        {
            v.push_back(-1);
            s.push(-1);
        }
        else if (!s.empty() && s.top()>arr[i])
        {
            v.push_back(s.top());
            s.push(arr[i]);
        }
        else if (!s.empty() && s.top()<=arr[i])
        {
            while (!s.empty() && s.top()<=arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
            s.push(arr[i]);
        }
    }
    reverse(v.begin(), v.end());
    return v;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> v=NextLargestToRight(arr, n);
    for (int i=0;i<v.size();i++)
    {
        cout<<v.at(i)<<" ";
    }
    return 0;
}