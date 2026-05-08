#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN
// thoughts- 2D dijkstra
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1,LLONG_MAX));
    for (int i = 1; i <= n; i++)
    {

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.push({0, i});
        dist[i][i] = 0;
        while (!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();
            // VIMPP OPTIMIZATION FOR PRIORITY QUEUE
            if (dist[i][node] < dis)
                continue;
            for (auto nbr : adj[node])
            {
                int adjNode = nbr.first;
                ll adjDist = nbr.second;
                if (dist[i][adjNode] > dis + adjDist)
                {
                    dist[i][adjNode] = dis + adjDist;
                    pq.push({dist[i][adjNode], adjNode});
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(dist[a][b]==LLONG_MAX?-1:dist[a][b])<<'\n';
    }

    return 0;
}