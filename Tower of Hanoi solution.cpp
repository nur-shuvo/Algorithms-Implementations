//   * gmail : nurshuvo51@gmail.com
//   * It'd be  better to google about this game and konow the concepts and then see
//   the code ...
// * Procedure : 1. if n==1
//                   beg to end
//                2. tower(n-1,beg,aux,end)
//                beg to end
//                3. tower (n-1,aux,beg,end)
#include<bits/stdc++.h>
void tower(int n,char  beg,char end,char aux)
{
    if(n==1){
       printf("Move disk 1 from %c to %c\n",beg,end);
       return;
    }
    tower(n-1,beg,aux,end) ;
    printf("Move disk %d from %c to %c\n",n,beg,end);
    tower(n-1,aux,beg,end) ;
}
int main()
{
    int n;
    printf("How many disks you want to move : ");
    scanf("%d",&n);
    tower(n,'A','B','C');
    return 0;
}
