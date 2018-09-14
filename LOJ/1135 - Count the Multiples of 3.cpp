#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define left st,(st+en)/2,n+n
#define right (st+en)/2+1,en,n+n+1
struct node
{
    int freq[3];
    node()
    {
        memset(freq,0,sizeof(freq));
    }
    node operator+(node a)
    {
        for(int i=0; i<3; i++) a.freq[i]+=freq[i];
        return a;
    }
};

int lazy[4*MAX];
node tree[4*MAX];
int ara[MAX];

void swwap(int &a,int &b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void prop(int st,int en,int n,int val)
{
    val%=3;
    for(int i=0; i<val; i++)
    {
        swwap(tree[n].freq[0],tree[n].freq[1]);
        swwap(tree[n].freq[0],tree[n].freq[2]);
    }
    if(st!=en)
    {
        lazy[n+n]+=val;
        lazy[n+n+1]+=val;
    }
}

void build(int st,int en,int n)
{
    if(st==en)
    {
        tree[n].freq[ara[st]%3]++;
        return;
    }
    build(left);
    build(right);
    tree[n]=tree[n+n]+tree[n+n+1];
    return;
}

void update(int st,int en,int n,int l,int r,int val)
{
    if(lazy[n])
    {
        prop(st,en,n,lazy[n]);
        lazy[n]=0;
    }
    if(en<l || st>r) return;
    if(en<=r && st>=l)
    {
        prop(st,en,n,val); // save to lazy[] for further traverse
        return;
    }
    update(left,l,r,val);
    update(right,l,r,val);
    tree[n]=tree[n+n]+tree[n+n+1];
}

node query(int st,int en,int n,int l,int r)
{
    if(lazy[n])
    {
        prop(st,en,n,lazy[n]);
        lazy[n]=0;
    }
    if(en<l || st>r) return node();
    if(en<=r && st>=l) return tree[n];
    return query(left,l,r)+query(right,l,r);
}

void CLR()
{
    memset(ara,0,sizeof(ara));
    memset(lazy,0,sizeof(lazy));
    memset(tree,0,sizeof(tree));
}
int main()
{
    //freopen("o.txt","w",stdout);

    int t,n,q,c,l,r;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        CLR();
        scanf("%d%d",&n,&q);

        build(0,n-1,1);

        printf("Case %d:\n",x);
        while(q--)
        {
            scanf("%d%d%d",&c,&l,&r);
            if(!c)
            {
                update(0,n-1,1,l,r,1);
            }
            else
            {
                printf("%d\n",query(0,n-1,1,l,r).freq[0]);
            }
        }
    }
    return 0;
}
