//  * Finding   (n! mod r )
//  * Formula : (a*b)%r = ( (a%r) * (b%r) )%r

#include<bits/stdc++.h>
using namespace std;

int n_factorial_mod_r(int n,int r);
int main()
{
    int n,r,fact;
    scanf("%d %d",&n,&r);
    fact=n_factorial_mod_r(n,r);
    printf("%d ! mod %d = %d\n",n,r,fact);
    return 0;
}
int n_factorial_mod_r(int n,int r)
{
int fact=1;
for(int i=1;i<=n;i++){
    fact=( (fact%r) * (i%r) )%r;
}
return fact;
}
