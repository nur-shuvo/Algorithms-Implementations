//you can print the size of a set by any node
#include<bits/stdc++.h>
using namespace std;
int parent[200000];
int Size[200000]; /* size[i] = s where s is the representative of the set  */

void makeset(int x)
{
    parent[x]=x;
    Size[x]=1;
}
int Find(int x)
{
    while(x!=parent[x]){
        x = parent[x];
    }
    return x; /* x means reprasentative */
}
void Union_by_size(int x,int y)
{
    int r = Find(x);
    int s = Find(y);
    if(r==s) return;
    else if(Size[r]>Size[s]){
        parent[s] = r;
        Size[r]+=Size[s];
    }
    else{
        parent[r] = s;
        Size[s]+= Size[r];
    }
}
int main()
{
    for(int i=1;i<=200000;i++) makeset(i);
    Union_by_size(3,4);
    Union_by_size(6,7);
    Union_by_size(3,6);

    int repr = Find(3);
    cout<<Size[repr]<<endl;

    return 0;
}






