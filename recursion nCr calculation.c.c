//** Calculating nCr with the help of dynammic programming
//** formula: nCr=(n-1)Cr + (n-1)C(r-1)
//** Base case : nCn=n ; nC1=1;
#include<stdio.h>
#define i64 long long
i64 dp[70][70];
long long int C(int n,int r)
{
    if(n==r) return n;
    if(r==1) return 1;
    if(dp[n][r]!=-1)
        return dp[n][r];
    else
        return dp[n][r]=C(n-1,r) + C(n-1,r-1);
}
int main()
{
    i64 i,j;
    for(i=0;i<70;i++)
        for(j=0;j<70;j++)
        dp[i][j]=-1;
    i64 rslt=C(5,1);
    printf("%lld\n",rslt);

}

