#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int>gr[1010];
bool vis[1010];
int sum,nodes,val[1010];
int checkSame[101][1001];

void Clear()
{
    memset(vis,false,sizeof(vis));
    memset(val,0,sizeof(val));
    for(int i=0; i<1010; i++) gr[i].clear();

}

void dfs(int u)
{
    vis[u]=true;
    sum+=val[u];
    nodes++;

    int sz=gr[u].size();
    for(int i=0; i<sz; i++)
    {
        int v=gr[u][i];
        if(!vis[v]) dfs(v);
    }
    return;
}

int main()
{
    int t,v,e,a,b;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        Clear();
        scanf("%d%d",&v,&e);
        for(int i=0; i<v; i++) scanf("%d",&val[i]);
        for(int i=0; i<e; i++)
        {
            scanf("%d%d",&a,&b);
            gr[a-1].pb(b-1);
            gr[b-1].pb(a-1);
        }
        bool ans=true;
        int track=-1;

        if(e==0)
        {
            for(int i=0; i<v; i++)
                (checkSame[x][val[i]])++;

            if(checkSame[x][val[0]]==v)
            {
                printf("Case %d: Yes\n",x);
                continue;
            }
        }
        for(int i=0; i<v; i++)
        {
            if(!vis[i])
            {
                sum=0;
                nodes=0;
                dfs(i);

                if(sum%nodes!=0)
                {
                    ans=false;
                    break;
                }
                else if(sum/nodes != track && i)
                {
                    ans=false;
                    break;
                }
                else
                {
                    track=sum/nodes;
                }
            }
        }
        if(!ans) printf("Case %d: No\n",x);
        else printf("Case %d: Yes\n",x);

    }
    return 0;
}
