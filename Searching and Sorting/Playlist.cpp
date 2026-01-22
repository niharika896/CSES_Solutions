#include <bits/stdc++.h>
using namespace std;
bool isPos(int target,vector<int>&a){
    unordered_map<int,int>mp;
    int l=0,r=0;
    int count=0;
    while(l<=r && r<a.size()){
        if(mp.find(a[r])!=mp.end()){
            l=max(l,mp[a[r]]+1);
        }
        mp[a[r]]=r;
        count=max(count,r-l+1);
        if(count==target)return true;
        r++;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int,int>mp;
    int l=0;int ans=0;
    for(int r=0;r<n;r++){
        if(mp.count(a[r])){
            l=max(l,mp[a[r]]+1);
        }
        mp[a[r]]=r;
        ans=max(ans,r-l+1);
    }
    // int l=1;int r=n;
    // int ans=1;
    // while(l<=r){
    //     int mid= l + (r-l)/2;
    //     if(isPos(mid,a)){
    //         ans=mid;
    //         l=mid+1;
    //     }
    //     else{
    //         r=mid-1;
    //     }
    // }
    cout<<ans;
    return 0;
}