// ...    for king's moves direction array will be
// ...    int fx[]={1,-1,0,0};
// ...    int fy[]={0,0,1,-1};


#include<bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define inf 1000000000
using namespace std;
int r = 8;
int c = 8;
int fx[]= {-2,-1, 1, 2, 2,1,-1,-2};
int fy[]= {-1,-2,-2,-1, 1,2, 2, 1};
int dis[50][50];

int bfs(int x,int y,int desx,int desy)
{
	for(int i=1;i<=8;i++) for(int j =1;j<=8;j++) dis[i][j] = inf;
	dis[x][y] = 0;
	queue<pii>q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		pii top = q.front();
		q.pop();
		for(int k=0;k<8;k++)
		{
			int tx = top.X + fx[k];
			int ty = top.Y + fy[k];
			if(tx>=1 && tx<=r && ty>=1 && ty<=c && dis[tx][ty] == inf)
			{
				dis[tx][ty] = dis[top.X][top.Y] + 1;
				q.push(make_pair(tx,ty));
			}
		}
	}
	return dis[desx][desy];
}

int main()
{
    string a,b;
    while(cin>>a>>b){
    int stx = a[0] - 96;
    int sty = a[1] - 48;

    int desx = b[0] - 96;
    int desy = b[1] - 48;
    cout<<"To get from "<<a<<" to "<<b<<" takes "<<bfs(stx,sty,desx,desy)<<" knight moves."<<endl;
    }
}
