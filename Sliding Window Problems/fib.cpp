#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

int printF(int n){
    if(n<0)return 0;
    if(n==0||n==1)return n;
    return printF(n-1)+printF(n-2);
}

int main()
{

int n=5;
cout<<printF(n);

return 0;
}