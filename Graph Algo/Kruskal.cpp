#include <bits/stdc++.h>
using namespace std;
int pr[300030];
struct edge
{
    int u,v,w;
    bool operator < (const edge &p) const
    {
        return w<p.w;
    }
};
int parent_khujo(int r)
{
    if(pr[r]==r) return r;
    return pr[r] = parent_khujo(pr[r]);
}
vector<edge>ed;
vector<edge>mstpath;

int Kruskal(int n)
{
    sort(ed.begin(),ed.end());
    for(int i=0; i<n; i++) pr[i]=i;
    int cnt=0,mst_w=0;
    for(int i=0; i<(int)ed.size(); i++)
    {
        int u,v;
        u=parent_khujo(ed[i].u);
        v=parent_khujo(ed[i].v);
        if(u!=v)
        {
            mstpath.push_back(ed[i]);
            pr[u]=v;
            cnt++;
            mst_w+=ed[i].w;
            if(cnt==n-1) break;
        }
    }
    return mst_w;
}

int KruskalForSecondBestMST(int n,int fx,int fy)
{
    for(int i=0; i<n; i++) pr[i]=i;
    int cnt=0,mst_w=0;
    for(int i=0; i<(int)ed.size(); i++)
    {
        int u,v;
        u=parent_khujo(ed[i].u);
        v=parent_khujo(ed[i].v);
        if(u!=v && !((ed[i].u==fx&&ed[i].v==fy)||(ed[i].u==fy&&ed[i].v==fx)))
        {
            mstpath.push_back(ed[i]);
            pr[u]=v;
            cnt++;
            mst_w+=ed[i].w;
            if(cnt==n-1) break;
        }
    }
    if(cnt!=n-1) return INT_MAX;
    return mst_w;
}
int main()
{
    int e,v,a,b,c;
    scanf("%d%d",&v,&e);
    for(int i=0; i<e; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        edge t;
        t.u=a;
        t.v=b;
        t.w=c;
        ed.push_back(t);
    }
    int MST=Kruskal(v);
    int tempMST=INT_MAX;

    int siz=mstpath.size();
    for(int i=0; i<siz; i++)
    {
        tempMST=min(tempMST,KruskalForSecondBestMST(v,mstpath[i].u,mstpath[i].v));
    }
    if(tempMST==INT_MAX) printf("No Second Best MST\n");
    else
        printf("%d\n",tempMST);
    return 0;
}
/*
7
11
0 1 7
0 3 5
3 1 9
1 2 8
1 5 7
2 5 5
3 5 15
3 4 6
4 5 8
4 6 11
5 6 9



*/
