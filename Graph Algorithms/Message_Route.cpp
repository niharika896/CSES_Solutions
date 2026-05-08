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
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // LEARNING:- whenever backtracking on adjacency list, all we need is a parent array;
    vector<int> parent(n + 1, -1);
    vector<int> vis(n + 1, 0);
    queue<int> q;
    int start = 1;
    int end = n;
    q.push(start);
    vis[start] = 1;
    bool isFound = false;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == end)
        {
            isFound = true;
            break;
        }
        for (int nbr : adj[cur])
        {
            if (!vis[nbr])
            {
                parent[nbr] = cur;
                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }
    if (!isFound)
        cout << "IMPOSSIBLE";
    else
    {
        vector<int> path;
        int cur = end;
        while (cur != -1)
        {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (int el : path)
        {
            cout << el << " ";
        }
    }

    return 0;
}