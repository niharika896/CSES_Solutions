#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN
int n,m;
class DisjointSet{
    private:
        vector<int>parent,rank,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        rank.resize(n+1,0);
        size.resize(n+1,1);
    }
    int findUpar(int n){
        if(parent[n]==n)return n;
        else return parent[n]=findUpar(parent[n]);
    }
    void UnionByRank(int n,int m){
        int ulp_n=findUpar(n);
        int ulp_m=findUpar(m);
        if(ulp_n==ulp_m)return;
        if(rank[ulp_n]<rank[ulp_m]){
            parent[ulp_n]=ulp_m;
        }
        else if(rank[ulp_m]<rank[ulp_n]){
            parent[ulp_m]=ulp_n;
        }
        else{
            parent[ulp_n]=ulp_m;
            rank[ulp_m]++;
        }
    }
    void UnionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
vector<vector<int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};

bool isValid(int i,int j){
    return i>=0 && i<n && j>=0 && j<m;
};

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);

cin>>n>>m;
vector<vector<char>>plan(n,vector<char>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>plan[i][j];
    }
}
DisjointSet ds(n*m+1);
queue<pair<int,int>>q;
vector<vector<int>>vis(n,vector<int>(m,0));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(plan[i][j]=='.' && !vis[i][j]){
            vis[i][j]=1;
            q.push({i,j});
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=x+dirs[k][0];
                    int nj=y+dirs[k][1];
                    int node=x*m+y;
                    int newNode=ni*m+nj;
                    if(isValid(ni,nj) && !vis[ni][nj] && plan[ni][nj]=='.'){
                        vis[ni][nj]=1;
                        q.push({ni,nj});
                        ds.UnionByRank(node,newNode);
                    }
                
            }
        }
    }
}
}
int count=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int node=i*m+j;
        if(plan[i][j]=='.' && ds.findUpar(node)==node)count++;
    }
}
cout<<count;
return 0;
}