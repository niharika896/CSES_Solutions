#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

bool isReached(int x, int y, int n, int m)
{
    return x == n - 1 || x == 0 || y == 0 || y == m - 1;
}
bool isValid(int x, int y, int n, int m)
{
    return x <= n - 1 && x >= 0 && y >= 0 && y <= m - 1;
}
bool isWalk(char c)
{
    return c == '.' || c == 'A';
};
vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
string dirChars = "ULRD";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    cin >> m;
    pair<int, int> start, end;
    queue<pair<int, int>> mq;
    vvi mdist(n, vi(m, 1e9));
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
                start = {i, j};
            else if (a[i][j] == 'M')
            {
                mdist[i][j] = 0;
                mq.push({i, j});
            }
        }
    }

    // mdists
    while (!mq.empty())
    {
        auto [x, y] = mq.front();
        mq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (isValid(nx, ny, n, m) && isWalk(a[nx][ny]) && mdist[nx][ny] > mdist[x][y] + 1)
            {
                mdist[nx][ny] = mdist[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    vvi parentDir(n, vi(m, -1));
    vvi vis(n, vi(m, 0));
    bool isFound = false;
    int count=0;
    while (!q.empty())
    {
        int sz = q.size();
        count++;
        while (sz--)
        {
            auto [x, y] = q.front();
            q.pop();
            if (isReached(x, y, n, m))
            {
                isFound = true;
                end = {x, y};
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (isValid(nx, ny, n, m) && isWalk(a[nx][ny]) && !vis[nx][ny] && mdist[nx][ny]>count)
                {
                    vis[nx][ny]=1;
                    parentDir[nx][ny] = i;
                    q.push({nx, ny});
                }
            }
            if (isFound)
            {
                break;
            }
        }
    }

    if(!isFound){
        cout<<"NO";
    }
    else{
        cout<<"YES"<<'\n';
        string path="";
        while(end!=start){
            int p=parentDir[end.first][end.second];
            path+=dirChars[p];

            end.first-=dirs[p][0];
            end.second-=dirs[p][1];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<'\n';
        cout<<path;
    }
    return 0;
}