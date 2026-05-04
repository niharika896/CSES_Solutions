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
int n;
cin>>n;
int k;
cin>>k;
int l = (n>>k)&1;
cout<<l;

return 0;
}