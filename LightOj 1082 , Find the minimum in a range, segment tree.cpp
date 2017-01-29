#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx * 4];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
//    tree[node] = min(tree[Left] ,tree[Right]);
    if(tree[Left]<tree[Right]) tree[node] = tree[Left];
    else tree[node] = tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return mx;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    if(p1<p2) return p1;
    else return p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = min(tree[Left] ,tree[Right]);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int t_case=1; t_case<=t; t_case++){
    printf("Case %d:\n",t_case);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    init(1,1,n);
    for(int i=1;i<=m;i++){
        int ll,jj;
        scanf("%d %d",&ll,&jj);
        printf("%d\n",query(1,1,n,ll,jj));
    }
    }
    return 0;
}

