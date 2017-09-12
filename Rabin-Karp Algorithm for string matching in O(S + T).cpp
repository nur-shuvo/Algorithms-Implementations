//t - text
//s - pattern to be matched
#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s, t; // input
    cin>>t>>s;

    // calculate all powers of p
    const int p = 31;
    vector<unsigned long long> p_pow(max(s.length(), t.length()));
    p_pow[0] = 1;
    for (size_t i = 1; i < p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p;

    // calculate hashes of all prefixes of text T
    vector<unsigned long long> h(t.length());
    for (size_t i = 0; i < t.length(); i++)
    {
        h[i] = (t[i] - 'a' + 1) * p_pow[i];
        if (i) h[i] += h[i - 1];
    }

    // calculate the hash of the pattern S
    unsigned long long h_s = 0;
    for (size_t i = 0; i < s.length(); i++)
        h_s += (s[i] - 'a' + 1) * p_pow[i];

    // iterate over all substrings of T having length |S| and compare them
    // with S
    for (size_t i = 0; i + s.length() - 1 < t.length(); i++)
    {
        unsigned long long cur_h = h[i + s.length () - 1];
        if (i) cur_h -= h [i - 1];

        // get the hashes multiplied to the same degree of p and compare them
        if (cur_h == h_s * p_pow[i])
            cout << "matched at "<< i <<endl;
    }
}
