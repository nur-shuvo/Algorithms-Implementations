#include<bits/stdc++.h>
using namespace std;
int graph[1000][1000];
bool visited[1000];
void tsp(int src, int V, int cont,int cost, int &ans){

    if(cont==V && graph[src][1]){
        ans = min(ans,cost+graph[src][1]);
        return ;
    }
    for(int i=1;i<=V;i++){
        if(!visited[i]&&graph[src][i]){
            visited[i]=true;
            tsp(i,V,cont+1,cost+graph[src][i],ans);
            visited[i]=false;
        }
    }
}
void reset(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            graph[i][j]=0;
        }
        visited[i]=false;
    }
}
int main()
{
    int V,E;
    reset();
    cin>>V>>E;
    for(int i=0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x][y]=w;
    }
    int ans=1e6;

    visited[1] = true;  /* as it is visited and we recur for the next node in case our your code */
    tsp(1,V,1,0,ans);
    cout<<ans<<endl;
    return 0;
}
