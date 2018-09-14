#include<bits/stdc++.h>
using namespace std;
#define in(n) scanf("%d",&n)
#define loop(i,n) for(int i=0;i<n;i++)
#define SET(n) memset(n,-1,sizeof(n))
#define CLR(n) memset(n,0,sizeof(n))
#define lojprint(x,n) printf("Case %d: %d\n",x,n)
vector<int>gra[50500];
int edge;
int vis[50500];

void dfs(int s)
{
    vis[s]=0;
    int i,l=gra[s].size();
    for(i=0; i<l; i++)
    {
        if(vis[gra[s][i]]==-1 || vis[gra[s][i]]==1)
        {
            edge++;
            dfs(gra[s][i]);
        }
    }
    vis[s]=1;
    return;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t,n,m,a,b;
    in(t);
    for(int x=1; x<=t; x++)
    {
        SET(vis);
        in(n);
        loop(i,n)
        {
            in(a);
            in(b);
            gra[a].push_back(b);
        }
        for(int i=0; i<=n; i++)
            sort(gra[i].begin(),gra[i].end());

        int ans,stans;
        ans=0;

        for(int i=1; i<=n; i++)
        {
            if(vis[i]==-1)
            {
                edge=1;
                dfs(i);
                if(ans<edge)
                {
                    ans=edge;
                    stans=i;
                }
            }
        }
        lojprint(x,stans);
         for(int i=0; i<50500; i++) gra[i].clear();
    }
    return 0;
}
