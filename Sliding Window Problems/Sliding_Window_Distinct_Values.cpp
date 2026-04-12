#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,k;
cin>>n>>k;
vi arr(n);
for(auto &x:arr){
    cin>>x;
}
int l=0,r=0;
unordered_map<int,int>mp; //num,last occurrence of num
int count=0;
while(r<n){
    if(mp.find(arr[r])==mp.end()){
        count++;
    }
    mp[arr[r]]=r;
    if(r-l+1==k){
        cout<<count<<" ";
        if(mp[arr[l]]<=l){
            count--;
            mp.erase(arr[l]);
        }
        l++;
    }
    r++;
}

return 0;
}