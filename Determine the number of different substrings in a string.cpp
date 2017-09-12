#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
int main()
{
    // Calculate all powers of p
    const int p = 31;
    vector <ULL> p_pow (50005);
    p_pow [0] = 1;
    for (size_t i = 1; i <p_pow.size (); ++ i)
        p_pow [i] = p_pow [i-1] * p;

    int t;
    cin>>t; getchar();
    while(t--){
    string s;
    cin>>s;
    int n =  s.length ();

    // Calculate the hashes of all prefixes
    vector <ULL> h (s.length ());
    for (size_t i = 0; i <s.length (); ++ i){
        h [i] = (s [i] - 'a' + 1) * p_pow [i];
        if (i) h [i] += h [i-1];
    }

    int result = 0; // stores the final answer

    // Iterate over length of substrings from 1 to n
    for (int l = 1; l <= n; ++ l){
        // Need to find the number of distinct substrings of length l

        // Get the hashes for all substrings of length l
        vector <long long> hs (n-l + 1);
        for (int i = 0; i<n-l+1;i++){
            long long cur_h = h [i+l-1];
            if (i) cur_h -= h [i-1];
            // Get all the hashes to the same degree
            cur_h *= p_pow [n-i-1];
            hs [i] = cur_h;
        }

        // Count the number of different hashes
        sort (hs.begin (), hs.end ());
        hs.erase (unique (hs.begin (), hs.end ()), hs.end ());
        result += (int) hs.size ();
    }
    cout << result;
    }
}
