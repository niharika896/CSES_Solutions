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
deque<int>q;
int exor=0;
for(int i=0;i<n;i++){
    while(!q.empty() && arr[q.back()]>=arr[i]){
        q.pop_back();
    }
    q.push_back(i);
    if(q.front()<=i-k){
        q.pop_front();
    }
    if(i>=k-1){
        exor^=arr[q.front()];
    }
}
cout<<exor;

return 0;
}