//  * gmail : nurshuvo51@gmail.com
//  * Implementation of Euler Totient function using Euler's
//    product Formula
//  * Implementation of Euler Totient function using Euler's
//    product Formula
//    algorithm :
//        1) Initialize result as n
//        2) Consider every number 'p' (where 'p' varies from 2 to √n).
//        If p divides n, then do following
//           a) Subtract all multiples of p from 1 to n [all multiples of p
//           will have gcd more than 1 (at least p) with n]
//           b) Update n by repeatedly dividing it by p.
//        3) If the reduced n is more than 1, then remove all multiples
//        of n from result.
#include<stdio.h>
int phi(int n)
{
    int result = n;   // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;

    return result;
}
int main()
{
    int n,i,result;

    for(i=1;i<=100;i++){
    result= phi(i);
    printf("phi(%d) = %d\n",i,result);
    }
    return 0;
}

