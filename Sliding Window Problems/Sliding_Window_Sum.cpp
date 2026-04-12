#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,k,a,b,c;
ll x;
cin>>n>>k>>x>>a>>b>>c;
vl arr(n);
arr[0]=x;
for(int i=1;i<n;i++){
    arr[i]=((ll)a*arr[i-1] + (ll)b)%(ll)c;
}

ll exor=0;
ll sum=0;
int l=0;int r=0;
while(r<n){
    sum+=arr[r];
    if((r-l+1) == k){
        exor^=sum;
        sum-=arr[l];
        l++;
    }
    r++;
}
cout<<exor;

return 0;
}