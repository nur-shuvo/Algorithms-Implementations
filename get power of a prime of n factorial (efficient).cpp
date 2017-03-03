#include<bits/stdc++.h>
using namespace std;
// Returns largest power of p that divides n!
long long int largestPower(long long int n,long long int p)
{
    // Initialize result
    long long int x = 0;

    // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n>1)
    {
        x += (n/p);
        n /= p;

    }
    return x;
}
int main()
{
    long long int res = largestPower(10,2);
    cout<<res<<endl;
}
