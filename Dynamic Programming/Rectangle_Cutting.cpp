#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

int recur(int x,int y,vii& memo){
    if(x==y)return 0;
    if(memo[x][y]!=-1)return memo[x][y];
    int xCut = imax;
    for(int i=1;i<=x-1;i++){
        xCut = min(xCut,1 + recur(i,y,memo)+recur(x-i,y,memo));
    }
    int yCut = imax;
    for(int i=1;i<=y-1;i++){
        yCut = min(yCut, 1+ recur(x,i,memo) + recur(x,y-i,memo));
    }
    return memo[x][y]=min(xCut,yCut);
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int a,b;
cin>>a>>b;
// vii memo(a+1,vi(b+1,-1));
vii memo(a+1,vi(b+1,0));
// cout<<recur(a,b,memo);
for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
        if(i==j){
            memo[i][j]=0;
            continue;
        }

        int ans=imax;

        for(int k=1;k<=i-1;k++){
            ans=min(ans,1+memo[k][j]+memo[i-k][j]);
        }
        for(int k=1;k<=j-1;k++){
            ans=min(ans,1+memo[i][k]+memo[i][j-k]);
        }
        memo[i][j]=ans;
    }
}

cout<<memo[a][b];
return 0;
}