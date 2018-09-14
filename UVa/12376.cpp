#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 2200
#define CLR(n) memset(n,0,sizeof(n))
#define SET(n) memset(n,-1,sizeof(n))
int vis[MAX];
int dist[MAX];
int val[MAX];
int ans=0,v,e,last;
vector<int> gr[MAX];


bool cmp(int a,int b)
{
    return a>b;
}
void VCLR(vector<int>a[])
{
    for(int i=0; i<MAX; i++) a[i].clear();
}
void dfs(int st)
{
    vis[st]=1;
    int dfsrunner=-1;;

    for(int i=0; i<gr[st].size(); i++)
    {
        if(dfsrunner<val[gr[st][i]])
        {
            dfsrunner=val[gr[st][i]];
            last=gr[st][i];
        }
    }
    if(vis[last]==0)
    {
        ans+=val[last];
        dfs(last);
    }
    return;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int a,b,t,cas;
    scanf("%d",&cas);
    for(int x=1; x<=cas; x++)
    {

        scanf("\n%d%d",&v,&e);
        for(int i=0; i<v; i++)
        {
            scanf("%d",&val[i]);
        }
        CLR(vis);
        CLR(dist);
        VCLR(gr);
        VCLR(gr);
        ans=0;
        for(int xx=1; xx<=e; xx++)
        {
            scanf("%d%d",&a,&b);
            gr[a].pb(b);
        }
        for(int i=0; i<MAX; i++) sort(gr[i].begin(),gr[i].end(),cmp);

        dfs(0);
        printf("Case %d: %d %d\n",x,ans,last);
    }
    return 0;
}
