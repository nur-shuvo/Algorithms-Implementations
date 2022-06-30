//you can print the size of a set by any node
#include<bits/stdc++.h>
using namespace std;
int parent[200000];
int size[200000]; /* size[i] = s where s is the representative of the set  */

void makeset(int x)
{
    parent[x] = x;
    size[x] = 1;
}
int find(int x)
{
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]); // path compression
}
void union_by_size(int x, int y)
{
    int r = find(x);
    int s = find(y);
    if(r == s) return;
    if (r != s) {
        if (size[r] < size[s])
            swap(r, s);
        parent[s] = r;
        size[r] += size[s];
    }
}

int main()
{
    for(int i = 1;i <= 200000; i++) makeset(i);
    union_by_size(3,4);
    union_by_size(6,7);
    union_by_size(3,6);

    int repr = find(3);
    cout<<size[repr]<<endl;

    return 0;
}






