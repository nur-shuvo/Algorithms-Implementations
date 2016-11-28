#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100000];

int visited[100000];
int dis[100000]; /* distance from starting vertax */
int path[100000]; /* we came to i from path[i] */

void bfs(int s,int n)
{
    for(int i=1;i<=n;i++) visited[i]=0;
    queue<int>Q;
    Q.push(s);
    visited[s] = 1;
    dis[s] = 0;
    path[s]=s;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();

        for(int i=0;i<adj[u].size();i++){
            if(visited[i]==0){
                int v=adj[u][i];
                visited[v]=1;
                dis[v]=dis[u]+1;
                path[v]=u;
                Q.push(v);
            }
        }
    }
//    vector<int>spath;
//    int t;
//    spath.push_back(t); /* shortest path from source to t node */
//    int now=t;
//    while(now!=s){
//        now=path[now];
//        spath.push_back(now);
//    }
//    int len=spath.size();
//    for(int i=len-1;i>=0;i--) printf("%d ",spath[i]); /*printing the path */
}
int main()
{
    /* Ebar ja iccha koro */
}

