//** This is called EUCLID algorithm ...
#include<stdio.h>
int GCD(int a ,int b);
int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)==3){
        printf("%d\n",GCD(c,GCD(a,b)));
    }
}
int GCD(int a ,int b)
{
    int temp,d;
    if(b==0) return a;
    if(a<b){
        temp=a;
        a=b;
        b=temp;
    }
    int r=a%b;
    return   GCD(b,r);

}
