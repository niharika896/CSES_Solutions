#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count=0;
    map<int,int>mp;
    for(auto k:a){
        if(mp.find(k)==mp.end()){
            count++;
            mp[k]=1;
        }
        else{
            mp[k]++;
        }
    }
    cout<<count;

 return 0;
}