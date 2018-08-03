#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,n) for(int i=0;i<n;i++)
vector<int>gr[100010];
int vis[100010],d[100010];

void BFS(int s)
{
    vis[s]=1;
    d[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int gr_size=gr[u].size();

        FOR(i,gr_size)
        {
            int v=gr[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return;
}
int main()
{
    int v,e,a,b;
    scanf("%d%d",&v,&e);
    FOR(i,e)
    {
        scanf("%d%d",&a,&b);
        gr[a].pb(b);
        gr[b].pb(a);
    }
    FOR(i,v)
    {
        if(vis[i]==0)
            BFS(i);
    }
    FOR(i,v)
    {
        printf("%d : %d\n",i,d[i]);
    }
    return 0;
}
/*
5 6
0 1
1 3
0 2
2 3
2 4
0 4


*/
