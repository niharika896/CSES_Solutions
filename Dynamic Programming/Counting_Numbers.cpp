#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vii vector<vector<int>>
#define vi vector<int>
#define imax INT_MAX
#define imin INT_MIN
ll memo[20][11][2];//idx,prev,lz

ll dp(string &num,ll idx,int tight, int prev, int lz){
    if(idx==num.size())return 1;

    if(!tight && memo[idx][prev+1][lz]!=-1){
        return memo[idx][prev+1][lz];
    }

    int limit = tight?num[idx]-'0':9;
    ll res=0;
    
    for(int i=0;i<=limit;i++){
        int ntight = tight&&(i==limit);
        int nlz= lz&&(i==0);

        if(!nlz && i==prev)continue;
        
        int nprev= nlz?-1:i;
        res+=dp(num,idx+1,ntight,nprev,nlz);
    }
    if(!tight)
    return memo[idx][prev+1][lz] = res;

    return res;
}

ll solve(ll x){
    if(x<0)return 0;
    memset(memo, -1, sizeof(memo));
    string s = to_string(x);
    return dp(s,0,1,-1,1);
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll a,b;
cin>>a>>b;
cout<<solve(b)-solve(a-1);


return 0;
}