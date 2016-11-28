#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
struct edge
{
	int u,v,w; /* u and v means two adjacent nodes,w is the cost */
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};
int pr[MAXN];
vector<edge>e;
int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}
int mst(int n)  /* here n means mot node koita */
{
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)pr[i]=i;

	int count=0,s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
//		    tar mane age theke ei 2 ta node e path nai,so pr[u]=v likhbo
			pr[u]=v;
			count++;
			s+=e[i].w;
			if(count==n-1) break; /* jehetu tree, n-1 sonkhok edge thakbe */
		}
	}
	return s;  /* minimum cost holo s */
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge get;
		get.u=u; get.v=v; get.w=w;
		e.push_back(get);
	}
	cout<<mst(n)<<endl;
	return 0;
}
