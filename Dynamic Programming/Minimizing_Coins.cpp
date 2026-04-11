#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

ll dp(vi& arr,int x,vl& memo){
    if(x<0) return 1e18;
    if(x==0)return 0;
    if(memo[x]!=-1)return memo[x];
    ll ways=1e18;
    for(auto m:arr){
        ways = min(ways,1 + dp(arr,x-m,memo));
    }
    return memo[x] = ways;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,x;
cin>>n>>x;
vi arr(n);
vl memo(x+1,-1);
for(auto &m:arr){
    cin>>m;
}

ll count = dp(arr,x,memo);
if (count>=1e18)cout<<-1;
else cout<<count;


return 0;
}