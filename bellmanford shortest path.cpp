//   complexity O(node*edge)
//   In case of negative cycle it works

#include<bits/stdc++.h>
#define pii pair<int,int>
#define inf  1000000000
#define X    first
#define Y    second
#define pb   push_back
#define Max_node  10000
using namespace std;
int dis[Max_node],cost[Max_node][Max_node];
void bellman(vector<pii>G,int source,int node)
{
    for(int i=1;i<=node;i++) dis[i] = inf;
    dis[source] = 0;
    for(int i=1;i<=node;i++){
        for(int i=0;i<G.size();i++){
            if(dis[G[i].X] + cost[G[i].X][G[i].Y]<dis[G[i].Y])
                dis[G[i].Y] = dis[G[i].X] + cost[G[i].X][G[i].Y];
        }
    }
    for(int i=0;i<G.size();i++){
            if(dis[G[i].X] + cost[G[i].X][G[i].Y]<dis[G[i].Y]){
                cout<<"Negative cycle detected"<<endl;
                break;
            }
        }
}
int main()
{
    int node,edge,u,v,w;
    cin>>node>>edge;
    vector<pii>G;

    for(int i=0;i<edge;i++){
        cin>>u>>v>>w;
        G.pb({u,v});
        cost[u][v] = w;
    }
    int source,des;

    while(1){
    cin>>source>>des;
    bellman(G,source,node);
    cout<<dis[des]<<endl;
    }
    return 0;
}
