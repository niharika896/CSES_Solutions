#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll median = a[n/2];
    ll cost = 0;
    for(ll i:a){
        cost+=llabs(i-median);
    }
    cout<<cost;
    return 0;
}