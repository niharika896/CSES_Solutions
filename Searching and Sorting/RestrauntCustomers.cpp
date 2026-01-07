#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    while (n--)
    {
        int a;
        int b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }
    sort(events.begin(), events.end());
    int curr=0;
    int maxC=INT_MIN;

    for(auto &e:events ){
        curr+=e.second;
        maxC=max(maxC,curr);
    }
    cout<<maxC;

    return 0;
}