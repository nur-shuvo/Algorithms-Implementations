#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

//for directed acyclic graph
//slightly modified dfs (topological sort)

vi ts,adj[100000];
int vis[100000];
void dfs2(int u)
{
    vis[u] = 1;
    for(int j=0;j<adj[u].size();j++){
        int v = adj[u][j];
        if(vis[v]==0) dfs2(v);
    }
    ts.pb(u); /* this is the only change */
}
int main()
{
    ts.clear();
    memset(vis,0,sizeof(vis));
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    for(int i=1;i<=v;i++){
        if(vis[i]==0) dfs2(i);
    }
    for(int i=ts.size()-1;i>=0;i--) cout<<ts[i]<<" ";
}


