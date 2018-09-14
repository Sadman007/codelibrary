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
int s,o,z,d;
vector<int> gr[MAX];
void dfs(int u)
{
    vis[u]=1;
    for(int i=0; i<gr[u].size(); i++)
    {
        int x = gr[u][i];

        if(vis[x]==0)
        {
            if(clr[u]==0)
            {
                clr[x]=1;
                z++;
            }
            else if(clr[u]==1)
            {
                clr[x]=0;
                o++;
            }
            dfs(x);
        }
    }
    return;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int v,e,a,b,t,st,color;
    cin >> t;
    while(t--)
    {
        CLR(vis);
        CLR(dist);
        SET(clr);
        for(int i=0; i<MAX; i++) gr[i].clear();
        cin >> v >> e;

        for(int i=0; i<e; i++)
        {
            cin >> a >> b;
            gr[a].pb(b);
            gr[b].pb(a);
        }
        int ans=0;
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<gr[i].size(); j++)
            {
                if(vis[gr[i][j]]==0)
                {
                    o=1;
                    z=0;
                    clr[gr[i][j]]=0;
                    dfs(gr[i][j]);
                    ans+=min(o,z);
                }
            }
        }

        bool breaker=false;
        for(int i=0; i<v; i++)
        {
            color = clr[i];
            for(int j=0; j<gr[i].size(); j++)
            {
                if(clr[i]==clr[gr[i][j]])
                {
                    breaker=true;
                    break;
                }
            }
            if(breaker==true) break;
        }

        if(breaker==true) cout << "-1\n";
        else
        {
            for(int i=0;i<v;i++)
            {
                if(clr[i]==-1) ans++;
            }
            cout << ans << endl;
        }

    }
    return 0;
}
