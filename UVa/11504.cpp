#include <bits/stdc++.h>
using namespace std;
vector<int>gr[100100];
stack<int>topo;
int clr[100100],t;
int d[100100],f[100100];
void dfs(int s)
{
    clr[s]=1;
    t++;
    d[s]=t;
    for(int i=0; i<gr[s].size(); i++)
    {
        int v = gr[s][i];
        if(clr[v]==0)
        {
            dfs(v);
        }
        /*else if(clr[v]>0)
        {

        }*/
    }
    topo.push(s);
    clr[s]=2;
    t++;
    f[s]=t;
}

int main()
{
   // freopen("out.txt","w",stdout);
    int n,m,a,b,cnt,tes;
    scanf("%d",&tes);
    while(tes--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<100100; i++) gr[i].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            gr[a].push_back(b);
        }
        memset(clr,0,sizeof(clr));
        for(int i=1; i<=n; i++)
        {
            if(clr[i]==0) dfs(i);
        }
        memset(clr,0,sizeof(clr));
        t=0;
        memset(d,0,sizeof(d));
        memset(f,0,sizeof(d));
        cnt=0;
        while(!topo.empty())
        {
            int v = topo.top();
            topo.pop();
            if(clr[v]==0)
            {
                cnt++;
                dfs(v);
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
