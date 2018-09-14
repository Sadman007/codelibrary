#include <bits/stdc++.h>
using namespace std;
vector<int>gr[2500];
vector<int>gr2[2500];
vector<int>scc[2500];
stack<int>topo;
stack<int>revtopo;
int clr[2500];
int d[2500],f[2500];
int comp;
int t;

void dfs(int s,vector<int>gr[])
{
    clr[s]=1;
    t++;
    d[s]=t;
    for(int i=0; i<gr[s].size(); i++)
    {
        if(clr[gr[s][i]]==0)
        {
            dfs(gr[s][i],gr);
        }
    }
    topo.push(s);
    clr[s]=2;
    t++;
    f[s]=t;
}
void dfs2(int s,vector<int>gr2[])
{
    scc[comp].push_back(s);
    clr[s]=1;
    t++;
    d[s]=t;

    for(int i=0; i<gr2[s].size(); i++)
    {
        if(clr[gr2[s][i]]==0)
        {
            dfs2(gr2[s][i],gr2);
        }
    }
    revtopo.push(s);
    clr[s]=2;
    t++;
    f[s]=t;
}

void reset()
{
    memset(clr,0,sizeof(clr));
    for(int i=0; i<2500; i++) gr[i].clear();
    for(int i=0; i<2500; i++) gr2[i].clear();
    for(int i=0; i<2500; i++) scc[i].clear();
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    t=0;
}
int main()

{
   // freopen("out.txt","w",stdout);
    int si,n,m,a,b,direc;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0) break;
        comp=0;
        reset();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&direc);
            if(direc==1) gr[a].push_back(b);
            else if(direc==2)
            {
                gr[a].push_back(b);
                gr[b].push_back(a);
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(clr[i]==0) dfs(i,gr);
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<gr[i].size(); j++)
            {
                gr2[gr[i][j]].push_back(i);
            }
        }
        memset(clr,0,sizeof(clr));
        memset(d,0,sizeof(d));
        memset(f,0,sizeof(f));
        t=0;
        while(!topo.empty())
        {
            int dfsrun=topo.top();
            topo.pop();
            if(clr[dfsrun]==0)
            {
                comp++;
                dfs2(dfsrun,gr2);
            }
        }
        if(comp==1) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
