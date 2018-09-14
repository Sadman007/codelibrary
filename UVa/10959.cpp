#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 2200
#define CLR(n) memset(n,0,sizeof(n))
#define SET(n) memset(n,-1,sizeof(n))
int vis[MAX];
int dist[MAX];

vector<int> gr[MAX];
void VCLR(vector<int>a[])
{
    for(int i=0; i<MAX; i++) a[i].clear();
}
void bfs(int st)
{
    queue<int>Q;
    Q.push(st);
    vis[st]=1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0; i<gr[u].size(); i++)
        {
            if(vis[gr[u][i]]==0)
            {
                int v = gr[u][i];
                vis[v]=1;
                dist[v]=dist[u]+1;
                Q.push(v);
            }
        }

    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int a,b,v,e,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("\n%d%d",&v,&e);
        CLR(vis);
        CLR(dist);
        VCLR(gr);
        for(int x=1; x<=e; x++)
        {
            scanf("%d%d",&a,&b);
            gr[a].pb(b);
            gr[b].pb(a);
        }

        bfs(0);
        for(int i=1; i<v; i++)
        {
            printf("%d\n",dist[i]);
        }
        if(t!=0) printf("\n");
    }
    return 0;
}
