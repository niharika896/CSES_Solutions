#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

class DisjointSet
{
private:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
    }
    int findUpar(int n)
    {
        if (parent[n] == n)
            return n;
        else
            return parent[n] = findUpar(parent[n]);
    }
    void UnionByRank(int n, int m)
    {
        int ulp_n = findUpar(n);
        int ulp_m = findUpar(m);
        if (ulp_n == ulp_m)
            return;
        if (rank[ulp_n] < rank[ulp_m])
        {
            parent[ulp_n] = ulp_m;
        }
        else if (rank[ulp_m] < rank[ulp_n])
        {
            parent[ulp_m] = ulp_n;
        }
        else
        {
            parent[ulp_n] = ulp_m;
            rank[ulp_m]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DisjointSet ds(n + 1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        ds.UnionByRank(a, b);
    }
    vector<int> upars;
    for (int i = 1; i <= n; i++)
    {
        if (ds.findUpar(i) == i)
        {
            upars.push_back(i);
        }
    }
    cout << upars.size() - 1 << '\n';
    for (int i = 0; i < upars.size() - 1; i++)
    {
        cout << upars[i] << " " << upars[i + 1] << '\n';
    }

    return 0;
}