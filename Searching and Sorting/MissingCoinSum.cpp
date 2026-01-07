#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    ll r=0;
    ll l=INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r+=a[i];
        l=min(a[i],l);
    }
    sort(a.begin(),a.end());
    long long ans=0;
    for(long long c:a ){
        if(c>ans+1){
            break;
        }
        ans+=c;
    }
    cout<<ans+1;
    return 0;
}