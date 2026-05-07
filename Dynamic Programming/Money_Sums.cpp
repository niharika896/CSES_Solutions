#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

void recur(vi& coins,int ind,set<int>&sums,int sum){
    if(ind==coins.size()){
        if(sum!=0)
        sums.insert(sum);
        return;
    }
    recur(coins,ind+1,sums,sum+coins[ind]);
    recur(coins,ind+1,sums,sum);
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
int sum=0;
vi coins(n);
for(auto &x:coins){
    cin>>x;
    sum+=x;
}
// set<int> sums;
// recur(coins,0,sums,0);
// vector<int>ans(sums.begin(),sums.end());
// cout<<ans.size()<<'\n';
// for(int i=0;i<ans.size();i++){
//     cout<<ans[i]<<" ";
// }
vector<bool>dp(sum+1,false);
dp[0]=true;
for(int coin:coins){
    for(int i=sum;i>=coin;i--){
        if(dp[i-coin]){
            dp[i]=true;
        }
    }
}
vi arr;
for(int i=1;i<dp.size();i++){
    if(dp[i])arr.push_back(i);
}
cout<<arr.size()<<'\n';
for(auto x:arr){
    cout<<x<<" ";
}
return 0;
}