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

int recur(vector<vector<char>> &grid,int x,int y,vii&memo){
    int n=grid.size();
    if(x>=n)return 0;
    if(y>=n)return 0;
    if(grid[x][y]=='*')return 0;
    if(x==n-1 && y==n-1)return 1;
    if(memo[x][y]!=-1)return memo[x][y];
    int paths=recur(grid,x+1,y,memo)+recur(grid,x,y+1,memo);
    return memo[x][y]=paths;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin >> n;
vector<vector<char>> grid(n,vector<char> (n));
vii memo(n,vi(n,0));
for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
// int a = recur(grid,0,0,0);
// cout<<recur(grid,0,0,memo);
if(grid[0][0]!='*'){
    memo[0][0]=1;
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j]=='*'){
            memo[i][j]=0;
            continue;
        }
        if(i>0){
            memo[i][j]=(memo[i][j]+memo[i-1][j])%mod;
        }
        if(j>0){
            memo[i][j]=(memo[i][j]+memo[i][j-1])%mod;
        }
    }
}
cout<<memo[n-1][n-1];
// vii memo(n,vi(n,-1));
return 0;
}