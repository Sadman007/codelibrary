#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100010
#define left st,(st+en)/2,n+n
#define right (st+en)/2+1,en,n+n+1

ll tree[4*MAX];
ll lazy[4*MAX];

void prop(int st,int en,int n)
{
    if(lazy[n]!=0)
    {
        tree[n]+=(en-st+1)*lazy[n];
        if(st!=en)
        {
            lazy[n+n]=lazy[n+n+1]=lazy[n];
        }
        lazy[n] = 0;
    }
}

void update(int st,int en,int n,int l,int r,int val)
{
    prop(st,en,n);
    if(l>en || st>r) return;

    if (st>=l && en<=r)
    {
        tree[n]+=(en-st+1)*val;
        if(st!=en)
        {
            lazy[n+n]=lazy[n+n+1]=val;
        }
        return;
    }

    update(left,l,r,val);
    update(right,l,r,val);
    tree[n] = tree[n+n]+tree[n+n+1];
}

int query(int st,int en,int n,int l,int r)
{
    if(l>en || st>r) return 0;
    prop(st,en,n);
    if(st>=l && en<=r) return tree[n];
    return query(left,l,r)+query(right,l,r);

}


int main()
{
    update(1,100,1,1,5,5);
    update(1,100,1,3,5,7);
    cout << query(1,100,1,1,7);
    return 0;
}
