//** Recursion to find 20 fibonacci numbers
#include<stdio.h>
int dp[22];
int F(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n]; /* dp[n]=-1 means empty and has to be calculated, else
                                return directly dp[n] which was previously calculated.*/
    else{
    dp[n]=F(n-1)+F(n-2);
    return dp[n];
    }

}
int main()
{
    int i;
    for(i=0;i<22;i++) dp[i]=-1;
    F(21);  /* Function call*/
    for(i=2;i<22;i++)
    printf("%d ",dp[i]);
}

