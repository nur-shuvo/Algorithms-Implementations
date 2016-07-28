//** Sieve algorithm for prime generator
//** Bitwise sieve uses less memory than this normal sieve

#include<stdio.h>
#include<math.h>
#define Max 10000000
char prime[Max];
void sieve()
{
    int i,j,x;
    for(i=0;i<Max;i++)
        prime[i]=0;
    prime[0]=prime[1]=1;
    for(i=4;i<=Max;i+=2)
        prime[i]=1;
        x=sqrt(Max);
    for(i=3;i<x;i+=2){
        for(j=i+i;j<Max;j+=i)
            prime[j]=1;
    }
}
int main()
{
    sieve();
    int num;
    for(num=0;num<=100;num++){
        if(prime[num]==0)
            printf("%d\n",num);
    }
}
