#include <bits/stdc++.h>
#define INF 1000000000000000000
using namespace std;
typedef pair<int,int> pii;
const int Size=1234567;
map<pii,int>mp;
vector<int>adj[Size];
vector<int>vec;
int path[Size];
long long dis[Size];
int Dijkstra(int source,int des)
{
    priority_queue<pair<int,int> >pq;
    for(int i=1;i<Size;i++){ dis[i]=INF; path[i]=-1;}
    pq.push(make_pair(0,source));
    dis[source]=0;
    while(!pq.empty()){
         int u=pq.top().second;
         if(u==des) break;
         pq.pop();
         int sz=adj[u].size();
         for(int i=0;i<sz;i++){
            int v=adj[u][i];
            pii x=make_pair(u,v);
            if(dis[u]+mp[x]<dis[v]){
                dis[v]=dis[u]+mp[x];
                path[v]=u;
                pq.push(make_pair((-1)*dis[v],v));
            }
         }
    }
    if(path[des]==-1){printf("NO PATH\n"); return -1;}
    /*path thakle path print korlam */
    else{
        int x=des;
        vec.push_back(x);
        while(x!=source){
            vec.push_back(path[x]);
            x=path[x];
        }
        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++) printf("%d ",vec[i]);
        printf("\n");
    }
    return dis[des];  /* cost */
}
int main(){
        int node,edge,u,v,w;
        scanf("%d %d",&node,&edge);
        for(int i=1;i<=edge;i++){
            scanf("%d %d %d",&u,&v,&w);
            adj[u].push_back(v);
            adj[v].push_back(u);
            mp[make_pair(u,v)]=w;
            mp[make_pair(v,u)]=w;
        }
        int source,des;
        scanf("%d %d",&source,&des);
        long long x=Dijkstra(source,des);
        if(x!=-1) printf("%lld\n",x);
        return 0;
}
