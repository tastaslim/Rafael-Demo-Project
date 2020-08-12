// Very famous you ca find statement anywhere just search on GFG.
// Another name of question is next largest element to Left

#include<bits/stdc++.h>
using namespace std;

// O(n^2) approach using brute force


/*
int* StockSpan(int *arr, int n)
{
    int *v=new int[n];
    int k=0;
    for (int i=0;i<n;i++)
    {
        int count=1;
        for (int j=i-1;j>=0;j--)
        {
            if (arr[j]<arr[i])
            {
                count++;
            }
            else
            {
                break;
            }

        }
        v[k++]=count;
    }
    return v;
}
*/

// Using stack and better one
vector<int> StockSpan(int *arr, int n)
{
    vector<int> v;
    stack<pair<int, int>>s;
    for (int i=0;i<n;i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (!s.empty() && s.top().first>=arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (!s.empty() && s.top().first<arr[i])
        {
            while (!s.empty() && s.top().first<arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }

        }
        s.push({ arr[i], i });
    }
    for (int i=0;i<v.size();i++)
    {
        v.at(i)=i-v.at(i);
    }
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
    vector<int>v=StockSpan(arr, n);
    for (int i=0;i<v.size();i++)
    {
        cout<<v.at(i)<<" ";
    }
    return 0;
}