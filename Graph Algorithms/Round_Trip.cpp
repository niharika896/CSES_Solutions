#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN
//thinking- this problem resembles detecting cycle in a graph ->min no of nodes in the cycle is 3->standard cycle
//when detecting and backtracking a cycle, dfs is the better approach than dfs

int cycle_start=0,cycle_end=0;

//attention to bool rtype of dfs ->pattern
bool dfs(int node,int par, vi&parent,vvi& adj, vi&vis){
    vis[node]=1;
    parent[node]=par;
    for(int nbr:adj[node]){
        if(!vis[nbr]){
            if(dfs(nbr,node,parent,adj,vis))return true;
        }
        else if(nbr!=par){
            cycle_start=nbr;
            cycle_end=node;
            return true;
        }
    }
    return false;
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n, m;
cin >> n >> m;
vvi adj(n + 1);
for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vi vis(n+1,0),parent(n+1,0);
for(int i=1;i<=n;i++){
    if(!vis[i]){
        if(dfs(i,-1,parent,adj,vis))break;
    }
}
if(cycle_start==0){
    cout<<"IMPOSSIBLE";
}
else{   
    vector<int>cycle;
    cycle.push_back(cycle_start);
    while(cycle_end!=cycle_start){
        cycle.push_back(cycle_end);
        cycle_end=parent[cycle_end];
    }
    cycle.push_back(cycle_end);
    reverse(cycle.begin(),cycle.end());
    cout<<cycle.size()<<'\n';
    for(int el:cycle){
        cout<<el<<" ";
    }
}
return 0;
}