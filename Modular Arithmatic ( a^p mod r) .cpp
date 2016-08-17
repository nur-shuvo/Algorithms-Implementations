// * Finding a^p %m by BIG MOD
#include<bits/stdc++.h>
#define i64 long long
i64 base_power_mod(i64 base,i64 power,i64 mod)
{
    int c;
    if(power==0)
        return 1;
        if(power%2==0){
//      i.e : 5^6 =  (5 ^3)* (5^3) ... Formula : (a*b)%m= ( (a%m)*(b%m) ) %m
        c=base_power_mod(base,power/2,mod);
        return ((c % mod) * (c % mod) )% mod;
    }
    else{
//        i.e : 5^3 = 5 * 5^2
        return ( ( base%mod)* base_power_mod(base,power-1,mod) )%mod;
    }
}
int main()
{
    i64 base,power,mod,result;
    scanf("%lld %lld %lld",&base,&power,&mod);
    result = base_power_mod(base,power,mod);
    printf("%lld\n",result);
    return 0;
}
