#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define imax INT_MAX
#define imin INT_MIN

// void recur(vector<vector<char>> &grid, set<string> &temp, string &curr, int x, int y)
// {
//     int n = grid.size();
//     if (x == n - 1 && y == n - 1)
//     {
//         curr.push_back(grid[x][y]);
//         temp.insert(curr);
//         curr.pop_back();
//         return;
//     }
//     curr.push_back(grid[x][y]);
//     if (x < n - 1)
//     {
//         recur(grid, temp, curr, x + 1, y);
//     }
//     if (y < n - 1)
//     {
//         recur(grid, temp, curr, x, y + 1);
//     }
//     curr.pop_back();
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // set<string>temp;
    // string curr;
    // recur(grid,temp,curr,0,0);
    // cout<<*temp.begin()<<endl;

    int dx[] = {1, 0};
    int dy[] = {0, 1};

    string ans;
    ans += grid[0][0];
    queue<pii> fronts;
    fronts.push({0, 0});
    while (ans.size() < 2 * n - 1)
    {
        char best = 'Z' + 1;
        queue<pii> tempFronts;
        while (!fronts.empty())
        {
            auto [ux, uy] = fronts.front();
            fronts.pop();
            for (int i = 0; i <= 1; i++)
            {
                int vx = ux + dx[i];
                int vy = uy + dy[i];
                if (vx >= n || vy >= n)
                    continue;
                if (grid[vx][vy] < best)
                {
                    best = grid[vx][vy];
                    while (!tempFronts.empty())
                    {
                        tempFronts.pop();
                    }
                tempFronts.push({vx, vy});
                }
                else if(grid[vx][vy]==best){
                    tempFronts.push({vx,vy});
                }
            }
        }
        ans += best;
        fronts=tempFronts;
    }
    cout << ans;
    return 0;
}

