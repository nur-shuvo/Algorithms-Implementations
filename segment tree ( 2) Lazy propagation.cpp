#include<bits/stdc++.h>
#define LL long long
#define mx 100005
using namespace std;

LL arr[mx];

struct info {
    LL prop, sum;
} tree[mx * 4];

void init(LL node, LL b, LL e)
{
    if (b == e) {
        tree[node].sum = arr[b];
        return;
    }
    LL Left = node * 2;
    LL Right = node * 2 + 1;
    LL mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void range_update(LL node, LL b, LL e, LL i, LL j, LL x)  /* logn  */
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) /* inside the range */
    {
        tree[node].sum += ((e - b + 1) * x);  /* e-b+1 nodes below,so e-b+1 times add x */
        tree[node].prop += x;  /* add x to the nodes below (range) */
        return;
    }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (b + e) >> 1;

    range_update(Left, b, mid, i, j, x);
    range_update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
    /* upore uthar somoy node gulo update hobe
       bam r dan paser sum cara-o jog hobe extra jog howa man */
}

LL query(LL node, LL b, LL e, LL i, LL j, LL carry = 0)  /* logn */
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);
        /* sum er sathe jog hobe sei range er sathe extra koto jog korte bolese seta */

    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (b + e) >> 1;

    LL p1 = query(Left, b, mid, i, j, carry + tree[node].prop); /* propagate value boye niye jacce carry variable */
    LL p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--){
    LL n,q;
    scanf("%lld %lld",&n,&q);

    for(LL i=1;i<=n;i++) arr[i] = 0;

    init(1,1,n);

    for(int i=1;i<=q;i++){
        LL u;
        scanf("%lld",&u);
        if(u==0){
            LL p,q,v;
            scanf("%lld %lld %lld",&p,&q,&v);  /* add v to that range */
            range_update(1,1,n,p,q,v);
        }
        if(u==1){
            LL p,q;
            scanf("%lld %lld",&p,&q);
            printf("%lld\n",query(1,1,n,p,q));
        }
    }
    /* clear */
    for(LL i=1;i<=n*4;i++) { tree[i].sum = 0; tree[i].prop=0; }
    }
    return 0;
}
