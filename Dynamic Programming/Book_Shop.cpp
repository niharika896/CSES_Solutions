#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN
const int mod = 1e9 + 7;

int recur(vi&prices, vi &pages, int ind, int maxCost, int currCost, int currPages,vii& memo){
    if(ind==prices.size())return currPages;
    if(memo[ind][currCost]!=-1)return memo[ind][currCost];
    int notTake = recur(prices,pages,ind+1,maxCost, currCost,currPages,memo);
    int take = 0;
    if(currCost+prices[ind]<=maxCost){
        take = recur(prices,pages,ind+1,maxCost,currCost+prices[ind],currPages+pages[ind],memo);
    }
    return memo[ind][currCost]=max(take,notTake);
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,x;
cin>>n>>x;
vi prices(n),pages(n);
for(int i=0;i<n;i++){
    cin>>prices[i];
}
for(int i=0;i<n;i++){
    cin>>pages[i];
}
vii memo(n+1,vi(x+1,0));
// cout<<recur(prices,pages,0,x,0,0,memo);
for(int i=n-1;i>=0;i--){
    for(int j=0;j<=x;j++){
        int notTake = memo[i+1][j];
        int take =0;
        if(j+prices[i]<=x)
        take = pages[i]+memo[i+1][j+prices[i]];
        memo[i][j]=max(take,notTake);
    }
}
cout<<memo[0][0];
return 0;
}