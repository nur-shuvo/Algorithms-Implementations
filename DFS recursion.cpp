#include<bits/stdc++.h>
using namespace std;

vector <int>adj[1000];
int vis[10000];

void dfs(int start)
{
   if(vis[start]==1) return;
   vis[start]=1;

   for(int i=0;i<adj[start].size();i++)
    dfs(adj[start][i]);
}
int main()
{
//   dfs diya ebar  bal falao
     return 0;
}
