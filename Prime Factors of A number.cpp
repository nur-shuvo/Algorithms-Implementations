//  * gmail : nurshuvo51@gmail.com
//  * Prime Factorilization of a number
#include<bits/stdc++.h>
int prime[100];
void prime_factor(int n)
{
    int i,j=0;
//    print the number of 2s that divide n
    while(n%2==0){
        prime[j++]=2;
        n/=2;
    }
//    n must be odd at this point . So we can skip one element ( i.e = i+=2)
    for(i=3;i*i<=n;i+=2){
        while(n%i==0){
            prime[j++]=i;
            n/=i;
        }
    }
//    at this point if n is greater than 2 than n itself is a prime factor
    if(n>2)
        prime[j++]=n;
//    printing the prime factors
    for(i=0;i<j;i++)
        printf("%d\n",prime[i]);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1){
    prime_factor(n);
    }
    return 0;
}

