#include<bits/stdc++.h>
#define LL long long
#define inf 1000000000
using namespace std;
// we keep all distance of nodes from source node in dis array
vector<int>adj[30];
int path[30],visited[30],dis[30];

int bfs(int s,int des)
{
    queue<int>Q;
    for(LL i=1;i<=30;i++) dis[i] = inf; /* ensure it is very big  */

    Q.push(s);
    dis[s] = 0;
    visited[s] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++){
              int v = adj[u][i];
              if (dis[v] == inf){
                 dis[v] = dis[u] + 1;
                 path[v] = u;
                 Q.push(v);
              }
        }
    }
    /* if u want to print the shortest path */
    int now = des;
    while(now!=s){
        now = path[now];
    }
    return dis[des];
}

int main()
{
    int t=1,x;
    int f,start,dest;
    while(scanf("%d",&x)==1){
               if(t!=1)
               printf("\n");
    for(int i=1;i<=20;i++) adj[i].clear();
    for(int j=1;j<=x;j++){
            scanf("%d",&f);
            adj[1].push_back(f);
            adj[f].push_back(1);
    }
    for(int i=2;i<=19;i++){
        scanf("%d",&x);
        for(int j=1;j<=x;j++){
            scanf("%d",&f);
            adj[i].push_back(f);
            adj[f].push_back(i);
        }
    }
    int par;
    scanf("%d",&par);
    printf("Test Set #%d\n",t);
    for(int i=1;i<=par;i++){
        scanf("%d %d",&start,&dest);
        printf("%2d to %2d: %d\n",start,dest,bfs(start,dest));
    }
    t++;
 }
 return 0;
}
