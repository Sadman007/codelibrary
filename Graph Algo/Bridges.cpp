#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>gr[666666];
vector< pair<int,int> > cut;
int clr[666666],t,d[666666],low[666666],pre[666666];

void dfs(int v)
{
    clr[v]=1;
    t++;
    d[v]=t;
    for(int i=0; i<gr[v].size(); i++)
    {
        int w=gr[v][i];
        if(clr[w]==0)
        {
            pre[w]=v;
            dfs(w);
            if(low[w]>d[v])
            {
                int uu,vv;
                uu=w;
                vv=v;
                if(uu>vv) swap(uu,vv);
                cut.pb(make_pair(uu,vv));
            }
            if(low[w]<low[v]) low[v]=low[w];
        }
        if(w!=pre[v])
        {
            if(d[w]<low[v]) low[v]=d[w];
        }
    }
    clr[v]=2;
    t++;
}
int main()
{
    int a,b,V,E;
    scanf("%d%d",&V,&E);
    for(int i=0; i<E; i++)
    {
        scanf("%d%d",&a,&b);
        gr[a].pb(b);
        gr[b].pb(a);
    }
    memset(low,127,sizeof(low));
    memset(d,127,sizeof(d));
    for(int i=0; i<V; i++)
    {
        if(clr[i]==0)
        {
            dfs(i);
        }
    }
    sort(cut.begin(),cut.end());
    for(int i=0;i<cut.size();i++)
    {
        printf("%d %d\n",cut[i].first,cut[i].second);
    }
    return 0;
}
