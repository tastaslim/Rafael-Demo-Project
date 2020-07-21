#include <iostream>
#include<unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(int i=0;i<n;i++){
        if(mp[arr[i]]>1){
            cout<<arr[i]<<" ";
            mp[arr[i]]=0;
        }
    }
	return 0;
}