#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN
const ll inf = LLONG_MAX;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vvl dist(n + 1, vl(n + 1, inf));
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    // floyd-warshal algo

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (dist[i][k] < inf && dist[k][j] < inf)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == inf)
            cout << -1 << '\n';
        else
            cout << dist[a][b] << '\n';
    }
    return 0;
}