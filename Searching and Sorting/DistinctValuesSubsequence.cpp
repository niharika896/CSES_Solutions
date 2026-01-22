#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll mod=1e9+7;
    int n;
    cin >> n;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        mp[a]++;
    }
    ll pro=1;
    for(auto &[num,freq]:mp){
        pro*=(freq+1);
        pro%=mod;
    }
    pro--;
    cout<<pro;
    return 0;
}