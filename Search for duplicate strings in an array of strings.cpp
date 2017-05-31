//Problem: Given a list of strings S[1..N]S[1..N], each no longer than MM characters, find all the duplicate
//strings and divide them into groups so that each group contains only the same string.
//
//From the obvious algorithm involving sorting the strings, we would get a time complexity of O(NMlogN)O(NMlogN)
//where the sorting requires O(NlogN)O(NlogN) comparisons and each comparison take O(M)O(M) time. However by using
//hashes, we reduce the comparison time to O(1), giving us an algorithm that runs in O(NM+NlogN) time.
//
//Algorithm: Calculate the hash of each string, and sort the strings on the basis of these hashes.
//link : file:///F:/Competitive%20Programming/Tutorial/String%20Hashing%20-%20E-Maxx%20Algorithms.html

#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
int main()
{
    int n = 5;
    vector <string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];

    // Calculate all powers of p up to 10,000 - the maximum length of a string
    const int p = 31;
    vector <ULL> p_pow (10000);
    p_pow [0] = 1;
    for (size_t i = 1; i <p_pow.size (); i++)
        p_pow [i] = p_pow [i-1] * p;

    // Calculate the hash of each string

    // hashes[] stores the hash value and the index of the string in the array s
    vector <pair <ULL, int>> hashes (n);

    for (int i = 0; i <n; ++ i){
        ULL hash = 0;
        for (size_t j = 0; j <s [i] .length (); ++ j)
            hash += (s [i] [j] - 'a' + 1) * p_pow [j];
        hashes [i] = make_pair (hash, i);
    }

    // Sort by hashes
    sort (hashes.begin (), hashes.end ());

    // Display the answer
    for (int i = 0, group = 0; i <n; ++ i)
    {
        if (i == 0 || hashes [i] .first!= hashes [i-1] .first)
            cout << "\n Group" << ++ group << ":";
        cout << " " << hashes [i] .second;
    }
    cout<<endl;
}
