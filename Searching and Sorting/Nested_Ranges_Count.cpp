#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vii vector<vector<int>>
#define vi vector<int>
#define imax INT_MAX
#define imin INT_MIN

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
vector<vector<int>>ranges;
for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    ranges.push_back({a,b,i});
}
vector<int>contains(n,0);
vector<int>containedBy(n,0);
sort(ranges.begin(),ranges.end(),[](const vi&a,const vi&b){
    if(a[0]!=b[0])return a[0]<b[0];
    return a[1]>b[1];
});

multiset<int>msu;
for(int i=0;i<n;i++){
    if(!msu.empty()){
        auto it = msu.lower_bound(ranges[i][1]);
        int len = distance(it,msu.end());
        containedBy[ranges[i][2]]= len;
    }
    msu.insert(ranges[i][1]);
}
multiset<int>msl;
for(int i=n-1;i>=0;i--){
    if(!msl.empty()){
        auto it = msl.upper_bound(ranges[i][1]);
        int len = distance(msl.begin(),it);
        contains[ranges[i][2]] = len;
    }
    msl.insert(ranges[i][1]);
}

for(int i=0;i<n;i++){
    cout<<contains[i]<<" ";
}
cout<<'\n';
for(int i=0;i<n;i++){
    cout<<containedBy[i]<<" ";
}




return 0;
}