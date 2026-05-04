#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

int dp(string& s1,string& s2,int x1,int x2,vii&memo){
    if(x1==s1.size())return s2.size() - x2;
    if(x2==s2.size())return s1.size() - x1;
    if(memo[x1][x2]!=-1)return memo[x1][x2];
    if(s1[x1]==s2[x2]){
        return dp(s1,s2,x1+1,x2+1,memo);
    }
    else{//not same add remove replace
        int mini=imax;
        mini=min(mini,1+dp(s1,s2,x1,x2+1,memo)); //add
        mini=min(mini,1+dp(s1,s2,x1+1,x2,memo));//remove
        mini=min(mini,1+dp(s1,s2,x1+1,x2+1,memo));//replace
        return memo[x1][x2]=mini;
    }
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
string s1,s2;
cin>>s1>>s2;
int x1=s1.size();
int x2=s2.size();
vii memo(x1,vi(x2,-1));
cout<<dp(s1,s2,0,0,memo);

return 0;
}