#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
string dirChars = "ULRD";
int n, m;

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
};

bool isWalk(char c)
{
    return c == '.' || c == 'B' || c == 'A';
};
// Learning:- DFS NEVER GIVES SHORTEST PATH;
//  bool dfs(pair<int, int> &start, pair<int, int> &end, vvi &vis, string &path, vvc &grid)
//  {
//      if (start == end)
//      {
//          return true;
//      }
//      auto [x, y] = start;
//      vis[x][y] = 1;
//      for (int i = 0; i < 4; i++)
//      {
//          int nx = x + dirs[i][0];
//          int ny = y + dirs[i][1];
//          pair<int, int> curr = {nx, ny};
//          if (isValid(nx, ny) && isWalk(grid[nx][ny]) && !vis[nx][ny])
//          {
//              path += mp[i];
//              if (dfs(curr, end, vis, path, grid))
//              {
//                  return true;
//              }
//              path.pop_back();
//          }
//      }
//      return false;
//  };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    pair<int, int> start, end;
    vector<vector<char>> grid(n, vector<char>(m));
    // input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }
    vvi vis(n, vi(m, 0));
    vvi parentDir(n, vi(m, -1));
    string path;
    string ans;
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    bool isFound = false;
    while (!q.empty())
    {

        auto [x, y] = q.front();
        q.pop();
        if (x == end.first && y == end.second)
        {
            isFound = true;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (isValid(nx, ny) && isWalk(grid[nx][ny]) && !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                parentDir[nx][ny] = i;
                q.push({nx, ny});
            }
        }
        if (isFound)
            break;
    }
    if (isFound)
    {
        cout << "YES" << '\n';
        string path="";
        pair<int,int>curr=end;
        while(curr!=start){
            int dir = parentDir[curr.first][curr.second];
            path+=dirChars[dir];

            curr.first-=dirs[dir][0];
            curr.second-=dirs[dir][1];
        }
        reverse(path.begin(),path.end());

        cout<<path.size()<<'\n';
        cout<<path<<'\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
    return 0;
}