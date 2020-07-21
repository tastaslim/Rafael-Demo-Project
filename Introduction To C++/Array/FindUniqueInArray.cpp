#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    // This method finds only unique in case of 1 unique and rest are present twice
    // int n;
    // cin>>n;
    // int *arr=new int[n];
    // int ans=0;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }

    // for(int i=0;i<n;i++)
    //     ans^=arr[i];
    // cout<<ans;

   //This works for any case
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
        if(mp[arr[i]]==1){
            cout<<arr[i]<<" ";
        }
    }
    
}


