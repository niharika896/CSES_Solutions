#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN
// IT IS AS SIMPLE AS CHECK IF A GRAPH IS BIPARTITE!!!!
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                int color = vis[node];
                for (int nbr : adj[node])
                {
                    if (!vis[nbr])
                    {
                        vis[nbr] = (color == 1 ? 2 : 1);
                        q.push(nbr);
                    }
                    else if (vis[nbr] == color)
                    {
                        cout << "IMPOSSIBLE";
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << vis[i] << " ";
    }
    return 0;
}