/*  * Implementation of Evaluating Ackermann funtion
   by recursive function
    * Easy to convert in code by using recursion ...
    * Procedure :
      1. if m=0 , Ackermann(m,n)=n+1
      2. if m!=0 but n=0, then Ackermann (m,n)=   Ackermann(m-1,1)
      3. if m!=0 and n!=0 , then Ackermann(m,n) = Ackermann(m-1,Ackermann(m,n-1))
*/
#include<stdio.h>
int ackermann (int m,int n)
{
    int c;
    if(m==0)
        return n+1;
    if(m!=0&&n==0)
         c=  ackermann(m-1,1);
    if(m!=0 && n!=0)
        c=ackermann(m-1,ackermann(m,n-1));
    return c;
}
int main()
{
    int m,n,result;
    scanf("%d %d",&m,&n);
    result = ackermann(m,n);
    printf("%d\n",result);
    return 0;
}
