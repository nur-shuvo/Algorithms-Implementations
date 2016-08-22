//  * Implementation of Euler Totient function using Euler's
//    product Formula
//  * Formula , phi(n) = n * [ ( 1 - 1/p1 ) * ( 1 - 1/p2 )* ( 1 - 1/p3 ) * ....*( 1 - 1/pn )  ]
//    where p1,p2,p3...,pn are all prime factors
#include<stdio.h>
int  Euler_totient(int n)
{
    int i,j=0,two;
    int prime[100]; /* prime factor gulo array ta te rakhbo , sob gulo factor distinct */
    double result= n;
    while(n%2==0){
         two=1;
//        prime[j++]=2;
         n/=2;
    }
    if(two==1)
        prime[j++]=2;
//    n must be odd at this point . So we can skip one element ( i.e = i+=2)
    for(i=3;i*i<=n;i+=2){
        while(n%i==0){
            n/=i;
        }
        prime[j++]=i;
    }
//    at this point if n is greater than 2 than n itself is a prime factor
    if(n>2)
        prime[j++]=n;

     for(i=0;i<j;i++){
        result*=(1.0-(1.0/prime[i]));
     }

      return (int)result ;
}
int main()
{
    int n,i,result;
    for(i=1;i<=10;i++){
    result= Euler_totient(i);
    printf("phi(%d) = %d\n",i,result);
    }
    return 0;
}
