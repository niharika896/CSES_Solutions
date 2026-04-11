#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN
ll mod = 1e9 + 7;
// ll dp(vi& arr,vl&memo,int x){

//     if(x<0)return 0;
//     if(x==0)return 1;
//     if(memo[x]!=-1)return memo[x];
//     ll ways = 0;
//     for(auto m:arr){
//         ways= (ways+ dp(arr,memo,x-m))%mod;
//     }
//     return memo[x]=ways;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vi arr(n);
    // vl memo(x+1,-1);
    vi memo(x + 1, 0);
    for (auto &m : arr)
    {
        cin >> m;
    }
    memo[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for(int a:arr){
            if(i>=a){
                memo[i]+=memo[i-a];
                if(memo[i]>=mod){
                    memo[i]-=mod;
                }
            }
        }
    }
    cout << memo[x];
    // cout<<dp(arr,memo,x);

    return 0;
}