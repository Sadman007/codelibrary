#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define SET(n) memset(n,-1,sizeof(n))
#define CLR(n) memset(n,0,sizeof(n))
#define MAX 1010
#define pb push_back
int vis[MAX];
int dist[MAX];
int clr[MAX];
int s,d;
vector<int> gr[MAX];
void dfs(int u)
{
    vis[u]=1;
    for(int i=0; i<gr[u].size(); i++)
    {
        int x = gr[u][i];
        if(clr[u]==0) clr[x]=1;
        else if(clr[u]==1) clr[x]=0;
        if(vis[x]==0) dfs(x);
    }
    return;
}

int main()
{
    int v,e,a,b;
    scanf("%d%d",&v,&e);
    for(int i=0; i<e; i++)
    {
        scanf("%d%d",&a,&b);
        gr[a].pb(b);
        gr[b].pb(a);
    }
    dfs(a);
    int c;

    bool bicolorable = true;
    for(int i=0; i<MAX; i++)
    {
        if(gr[i].size()>0)
        {
            c=clr[i];

            for(int j=0; j<gr[i].size(); j++)
            {
                if(c==clr[gr[i][j]])
                {
                    bicolorable=false;
                    break;
                }
            }
        }
        if(bicolorable==false) break;
    }
    if(bicolorable==false) cout << "NOT BIPARTITE.\n";
    else cout << "BIPARTITE.\n";
    return 0;
}
