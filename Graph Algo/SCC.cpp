#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>gr[100010];
vector<int>trgr[100010];
stack<int>topo,SCC;
int clr[100010],t,x;
int d[100010],f[100010];

void dfs(int u)
{
    clr[u]=1;
    t++;
    d[u]=t;
    for(int i=0; i<gr[u].size(); i++)
    {
        if(clr[gr[u][i]]==0)
            dfs(gr[u][i]);
    }
    topo.push(u);
    t++;
    f[u]=t;
}

void dfsForSCC(int u)
{
    clr[u]=1;
    SCC.push(u);
    for(int i=0; i<trgr[u].size(); i++)
    {
        if(clr[trgr[u][i]]==0)
        {
            dfsForSCC(trgr[u][i]);
        }
    }
}

void prstack(stack<int>a)
{
    while(!a.empty())
    {
        int y=a.top();
        printf("%d\n",y);
        a.pop();
    }
}
void TRgr()
{
    for(int i=0; i<100010; i++)
    {
        for(int j=0; j<gr[i].size(); j++)
        {
            trgr[gr[i][j]].pb(i);
        }
    }
}
int main()
{
    int v,e,a,b;
    scanf("%d%d",&v,&e);
    for(int i=0; i<e; i++)
    {
        scanf("%d%d",&a,&b);
        gr[a].pb(b);
    }
    for(int i=0; i<v; i++)
    {
        if(clr[i]==0) dfs(i);
    }

    TRgr();
    memset(clr,0,sizeof(clr));

    while(!topo.empty())
    {
        int x=topo.top();
        topo.pop();
        if(clr[x]==0)
        {
            dfsForSCC(x);
        }

        if(SCC.size()>0)
        {
            printf("%d",SCC.top());
            SCC.pop();
            while(!SCC.empty())
            {
                printf(" %d",SCC.top());
                SCC.pop();
            }
            printf("\n");
        }
    }
    return 0;
}
