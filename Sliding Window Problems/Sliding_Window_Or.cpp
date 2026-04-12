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
int n,k;
ll x,a,b,c;
cin>>n>>k>>x>>a>>b>>c;
vi arr(n);
arr[0] = (int)x;
for(int i=1;i<n;i++){
    arr[i] = (int)(((ll)a * arr[i - 1] + b) % c);
}

vi pre(n);
vi suf(n);

for(int i=0;i<n;i++){
    if(i%k==0)pre[i]=arr[i];
    else pre[i]=(pre[i-1]|arr[i]);
}

for(int i=n-1;i>=0;i--){
    if(i==n-1||(i+1)%k==0)suf[i]=arr[i];
    else suf[i]=suf[i+1]|arr[i];
}
int exor=0;
for(int i=0;i<=n-k;i++){
    int stop = i+k-1;
    int wOr = suf[i]|pre[stop];
    exor^=wOr;
}
cout<<exor;

return 0;
}