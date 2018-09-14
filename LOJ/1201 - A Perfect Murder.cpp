#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int dp[1010][2],par[1010];
vector<int>gr[1010];

int solve(int node,int guard)
{
    if(gr[node].size()==0) return 0;
    if(dp[node][guard]!=-1) return dp[node][guard];

    int numOfGuards=0;

    for(int i=0; i<gr[node].size(); i++)
    {
        int v=gr[node][i];
        if(par[node]!=v)
        {
            par[v]=node;
            if(guard==0) numOfGuards+=solve(v,1);
            else numOfGuards+=min(solve(v,0),solve(v,1));
        }
    }
    return dp[node][guard]=numOfGuards+guard;
}

pii vertexCover(int v,int e)
{
    pii both;
    memset(dp,-1,sizeof(dp));
    memset(par,-1,sizeof(par));

    int ans=0;

    for(int i=1; i<=v; i++)
    {
        if(dp[i][0]==-1 || dp[i][1]==-1) // if i is a node from different tree
        {
            ans+=min(solve(i,0),solve(i,1));
        }
    }

    both.first=ans; //minimum
    both.second=v-ans; //maximum
    for(int i=0; i<1010; i++) gr[i].clear();
    return both;
}
int main()
{
    int t,v,e;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d%d",&v,&e);
        for(int i=0; i<e; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        printf("Case %d: %d\n",x,vertexCover(v,e).second);
    }
    return 0;
}
