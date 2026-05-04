#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN
const int mod=1e9+7;
//2 0 5 2
int recur(vi&arr, int limit,int ind,int prev,vii& memo){
    if(ind==arr.size())return 1;
    if(memo[ind][prev]!=-1)return memo[ind][prev];
    ll ways = 0;

    if(arr[ind]!=0){
        if(prev==0||abs(arr[ind]-prev)<=1){
            ways = recur(arr,limit,ind+1,arr[ind],memo);
        }
        else{
            ways=0;
        }
    }
    else{
        // for(int i=1;i<=limit;i++){
        //     if(prev==0||abs(i-prev)<=1){
        //         ways = (ways + recur(arr,limit,ind+1,i,memo))%mod;
        //     }
        // }
        if(prev<=limit-1){
            ways = (ways + recur(arr,limit,ind+1,prev-1,memo)+recur(arr,limit,ind+1,prev,memo)+recur(arr,limit,ind+1,prev+1,memo))%mod;
        }
        else if(prev==limit){
            ways = (ways + recur(arr,limit,ind+1,prev-1,memo)+recur(arr,limit,ind+1,prev,memo))%mod;
        }
        else if(prev-1==limit){
            ways = (ways + recur(arr,limit,ind+1,prev-1,memo))%mod;
        }
    }
    return memo[ind][prev]=ways;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m;
cin>>n>>m;
vi arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vii memo(n+1,vi(m+1,0));
// cout<<recur(arr,m,0,0,memo);
for(int i=0;i<=m;i++){
    memo[n][i]=1;
}
for(int i=n-1;i>=0;i--){
    for(int j=0;j<=m;j++){
        if(arr[i]!=0){
            if(j==0||abs(arr[i]-j)<=1){
                memo[i][j]=memo[i+1][arr[i]];
            }
            else{
                memo[i][j]=0;
            }
        }
        else{
            // for(int k=1;k<=m;k++){
            //     if(j==0||abs(k-j)<=1){
            //         memo[i][j]= (memo[i][j]+memo[i+1][k])%mod;
            //     }
            // }
            ll ways = 0;
            if(j==0){
                for(int k=1;k<=m;k++){
                    ways=(ways+memo[i+1][k])%mod;
                }
            }
            //2 0 5 3
            else{
                if(j-1>=1) ways = (ways + memo[i+1][j-1])%mod;
                ways = (ways+memo[i+1][j])%mod;
                if(j+1<=m) ways = (ways+memo[i+1][j+1])%mod;    
            }
            memo[i][j]=ways;
        }
    }
}
cout<<memo[0][0];
return 0;
}