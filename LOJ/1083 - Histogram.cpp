#include <bits/stdc++.h>
using namespace std;
#define left st,(st+en)/2,n+n
#define right (st+en)/2+1,en,n+n+1
#define MAX 30100
#define ii pair<int,int>

int n,ara[MAX];
ii tree[4*MAX];

ii MIN(ii a,ii b)
{
    ii temp;
    temp.first = min(a.first,b.first);
    if(temp.first==a.first) temp.second = a.second;
    else temp.second = b.second;
    return temp;
}

void build(int st,int en,int n)
{
    if(st==en)
    {
        tree[n].first=ara[st];
        tree[n].second = st;
        return;
    }
    build(left);
    build(right);
    tree[n]=MIN(tree[n+n],tree[n+n+1]);
}

ii getMinIdx(int st,int en,int n,int l,int r)
{
    if(r<st || en<l) return {INT_MAX,-1};
    if(r>=en && st>=l) return tree[n];
    return MIN(getMinIdx(left,l,r),getMinIdx(right,l,r));
}

int solve(int l,int r)
{
    if(l>r) return 0;
    if(l==r) return ara[l];

    int min_idx = getMinIdx(0,n-1,1,l,r).second;
    int min_val = ara[min_idx];

    return max(min_val*(r-l+1),max(solve(l,min_idx-1),solve(min_idx+1,r)));

}

int main()
{
    int t;
    scanf("%d",&t);

    int cs=1;

    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&ara[i]);
        build(0,n-1,1);
        printf("Case %d: %d\n",cs++,solve(0,n-1));
    }

    return 0;
}
