/** dfs+segment tree **/
#include<bits/stdc++.h>
#define pb push_back
#define LL long long
#define N 100000
#define mx 100005
using namespace std;
vector<int>List,height(4*N),adj[N+1];
int tree[N*4],vis[N+1],first[N+1];
void lca_dfs(int u,int h=1)
{
    vis[u] = 1;
    height[u] = h;
    List.pb(u);
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(!vis[v]){
            lca_dfs(v,h+1);
            List.pb(u);
        }
    }
}
/** range minimum query **/
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = List[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    if(height[tree[Left]]<height[tree[Right]]) tree[node] = tree[Left];
    else tree[node] = tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return mx;  /*ei segment e ekta boro num return korey dilam jehetu relevant na  */
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    if(height[p1]<height[p2]) return p1;
    else return p2;
}


int lca_query(int a,int b)
{
    a = first[a]; b = first[b];
    if(a>b) swap(a,b);
    return query(1,1,List.size()-1,a,b);
}

void lca_prepare(int root)
{
    height[mx] = mx;
    List.pb(0); /* making list 1-indexed */
    lca_dfs(root);
    init(1,1,List.size()-1);
    memset(first,0,sizeof(first));
    for(int i=1;i<List.size();i++){
        int v = List[i];
        if(first[v]==0) first[v] = i;
    }

}

void Clear(int n)
{
    memset(vis,0,sizeof(vis));
    List.clear();
    height.resize(4*N);
    for(int i=1;i<=n;i++) adj[i].clear();
}

int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        /** build tree **/
        int n;
        scanf("%d",&n);
        for(int k=1;k<=n;k++){
            int child;
            scanf("%d",&child);
            while(child--){
                int nn;
                scanf("%d",&nn);
                adj[k].pb(nn);
                adj[nn].pb(k);
            }
        }
        lca_prepare(1);
        int query; scanf("%d",&query);
        printf("Case %d:\n",tt);
        while(query--){
            int u,v; scanf("%d%d",&u,&v);
            printf("%d\n",lca_query(u,v));
        }

     Clear(n);
    }

}
