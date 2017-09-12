/**
You can do a bit mask DP whenever you feel "To solve a sub problem, I need the previously visited positions/indices".
In such problems, you will need to pass n boolean variables or a map<int, bool> as parameter(s) to your sub states.

Instead of using passing n boolean variables as parameters, combine all the boolean variables into a string something
like "10011001" and convert it into base 10 decimal integer (i.e. 153)(considered as mask) and pass it as the parameter.

One of the limitations is that integer can store only up to 32 bits (i.e. n must be at most 32). The other limitation is
the memorization space of your states. It takes 2^n storage space. As the storage space in your program is approximately
of order 10^7, n must be approximately at most 20.


complexity : t*O(2^n * n^2)
tutorial : safayet
**/

#include<bits/stdc++.h>
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

using namespace std;


int w[20][20];
int n;
int dp[(1<<15)+2];
int call(int mask)
{
	if(mask==(1<<n)-1) return 0;
	if(dp[mask]!=-1) return dp[mask];
	int mn=1<<28;
	for(int i=0;i<n;i++){
		if(check(mask,i)==0){  /* not taken */
			int price = w[i][i];
			for(int j=0;j<n;j++){
				if(i!=j and check(mask,j)!=0){ /* if i! = j and j is taken */
					price+=w[i][j];
				}
			}
			int ret = price + call(Set(mask,i));  /* Set(mask,i) goes to next state */
			mn = min(mn,ret);
		}
	}
	return dp[mask]=mn;
}
int main()
{
        int t;
        cin>>t;
        for(int tt=1;tt<=t;tt++){
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&w[i][j]);  /** w[i][i] is the base price of i **/
			}
		}

		int ret = call(0);
		printf("Case %d: %d\n",tt,ret);
        }
}
