#include<bits/stdc++.h>
using namespace std;
#define Max 100000

int parent[Max];

void makeset(int n)
{
   parent[n]=n;
}

int Find(int reprasentative)
{
        if (parent[reprasentative] == reprasentative){
        return reprasentative;
      }
     return parent[reprasentative] = Find(parent[reprasentative]);
}


void Union(int a,int b)
{
 int u = Find(a);
 int v = Find(b);
 if(u == v){
   printf("Frnds");
 }
 else parent[u]=v;  /* Frnd kore dilam  */
}
int main()
{
   for(int i=1;i<=5;i++) makeset(i);  /* At first sob node e sobar representitive */
   parent[1]=2;
   parent[2]=3;
   parent[4]=5;
   Union(2,5);  /* tara graph e age theke frnd na , ekhane frnd holo  */
//   Union(1,5);  /*line 37 e frnd korsi, so ekhon frnd */
   return 0;
}
