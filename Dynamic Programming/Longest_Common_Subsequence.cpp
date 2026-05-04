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
int l1,l2;
cin>>l1>>l2;
vi s1(l1);
for(auto&x:s1){
    cin>>x;
}
vi s2(l2);
for(auto &x:s2){
    cin>>x;
}
vii dp(l1+1,vi(l2+1,0));
for(int i=1;i<=l1;i++){
    for(int j=1;j<=l2;j++){
        if(s1[i-1]==s2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
        }
        else{
            dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
cout<<dp[l1][l2]<<'\n';
vi lcs;
int i=l1,j=l2;
while(i>0 && j>0){
    if(s1[i-1]==s2[j-1]){
        lcs.push_back(s1[i-1]);
        i--;j--;
    }
    else if(dp[i-1][j]>dp[i][j-1]){
        i--;
    }
    else{
        j--;
    }
}
reverse(lcs.begin(),lcs.end());
for(auto x:lcs){
    cout<<x<<" ";
}
return 0;
}