#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1); // node,dist
    vector<ll>dist(n+1,LLONG_MAX);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        auto [dis,node]=pq.top();
        pq.pop();
        //VIMPP OPTIMIZATION FOR PRIORITY QUEUE
        if(dist[node]<dis)continue;
        for(auto nbr:adj[node]){
            int adjNode=nbr.first;
            ll adjDist=nbr.second;
            if(dist[adjNode]>dis+adjDist){
                dist[adjNode]=dis+adjDist;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}