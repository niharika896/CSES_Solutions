#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>>m;
    while(n--){
        int a,b;
        cin>>a>>b;
        m.push_back({a,b});
    }
    sort(m.begin(),m.end(),[](const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    });

    int count=0;
    int end=0;
    for(auto &movie:m){
        if(movie.first>=end){
            count++;
            end=movie.second;
        }
    }
    cout<<count;

    return 0;
}