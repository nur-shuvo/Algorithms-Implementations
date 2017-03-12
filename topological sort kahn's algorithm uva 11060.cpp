#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

//for directed acyclic graph (DAG)
//slightly modified bfs (topological sort)
//you can print the sort in increasing or decreasing order
//based on modified bfs

vi ts,adj[100000];
int indegree[10000];
int main()
{
        int v,e;
        int cas =1;
        while(scanf("%d",&v)==1){

        memset(indegree,0,sizeof(indegree));
        for(int i=1;i<=v;i++) adj[i].clear();
        map<string,int>mp;
        map<int,string>mp2;

        for(int i=0;i<v;i++){
            string ss;
            cin>>ss;
            mp[ss] = i+1;
            mp2[i+1] = ss ;
        }
        scanf("%d",&e);
        for(int i=0;i<e;i++){
            string u,v;
            cin>>u>>v;
            adj[mp[u]].pb(mp[v]);
            indegree[mp[v]]++;
        }

//        main part , run kahn's algo like bfs
        priority_queue<int, vector<int>,greater<int> > pq;  /* min pq nilam karon holo smallest to
        largest node precedence problem staement e , dorkar porle maximum pq nite hobe */

        for(int i=1;i<=v;i++){
            if(indegree[i]==0) pq.push(i);
        }
        vector<int>ts;

        while(!pq.empty()){
            int u = pq.top();
            pq.pop();
            ts.push_back(u);
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                indegree[v]--;
                if(indegree[v]==0 )
                    pq.push(v);
            }
        }
        /* queue khali howar por o jodi kono node er in degree 0 na thake tahole
        graph e cycle ase */

        printf("Case #%d: ",cas++);
        printf("Dilbert should drink beverages in this order: ");
        for(int i=0;i<ts.size();i++) { if(i!=0) printf(" "); cout<<mp2[ts[i]]; }
        printf(".");
        printf("\n\n");
        }
        return 0;
}
