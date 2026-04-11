#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vii vector<vector<int>>
#define vi vector<int>
#define imax INT_MAX
#define imin INT_MIN
int mod = 1e9 + 7;

ll recur(vector<ll>&dp, int n){
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    ll ways = 0;
    for(int i=1;i<=6;i++){
        ways = (ways + recur(dp,n-i))%mod;
    }
    return dp[n]=ways;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
// vector<ll>dp(n+1,-1);
// cout<<recur(dp,n);


vector<ll>dp(n+1,0);
dp[0]=1;
for(int i=1;i<=n;i++){
    for(int j=1;j<=6;j++){
        if((i-j)>=0)
        dp[i] = (dp[i] + dp[i-j])%mod;
    }
}
cout<<dp[n];
return 0;
}