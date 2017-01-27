#include<bits/stdc++.h>
#define LL long long
#define inf 1000000000
using namespace std;

void CLR(vector<int>adj[])
{
    int s = 250;
    for(int i=0;i<s;i++) adj[i].clear();
}

// we keep all distance of nodes from source node in dis array
vector<int>adj[250];
int path[250],visited[250],dis[250];
int color[250];
int bfs(int s,int des)
{
    queue<int>Q;
    for(LL i=0;i<250;i++) dis[i] = inf; /* ensure it is very big  */
    memset(color,-1,sizeof(color));

    Q.push(s);
    dis[s] = 0;
    visited[s] = 1;
    while(!Q.empty()){
        int u = Q.front();
        if(color[u]==-1)
        color[u] = 1;
        Q.pop();
        for(int i=0;i<adj[u].size();i++){
              int v = adj[u][i];
              if (dis[v] == inf){
                 if(color[u]==1) color[v] = 2;
                 else color[v] = 1;
                 dis[v] = dis[u] + 1;
                 path[v] = u;
                 Q.push(v);
              }
              else{
                if(color[v]==color[u]) return 0;
              }
        }
    }
    return 1;
}

int main()
{
    int n,e,u,v;
    while(scanf("%d",&n)==1 && n!=0 ){
        CLR(adj);
        scanf("%d",&e);
        for(int i=0;i<e;i++){
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ck = bfs(0,n-1);
        if(ck==1) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}




