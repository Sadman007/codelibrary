#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define TREE 3
#define BACK 4
#define FORWARD 5
#define CROSS 6

vector<int>gr[100010];
int clr[100010],d[100010],f[100010],t,edge_type[500][500],par[100010];
void DFS(int u)
{
    clr[u]=GRAY;
    t++;
    d[u]=t;

    int gr_size=gr[u].size();
    FOR(i,gr_size)
    {
        int v=gr[u][i];
        if(clr[v]==WHITE)
        {
            edge_type[u][v]=TREE;
            par[v]=u;
            DFS(v);
        }
        else if(clr[v]==GRAY)
        {
            edge_type[u][v]=BACK;
        }
        else if(clr[v]==BLACK)
        {
            if(d[u]<d[v]) edge_type[u][v]=FORWARD;
            else edge_type[u][v]=CROSS;
        }
    }

    clr[u]=BLACK;
    t++;
    f[u]=t;
}
int main()
{
    int v,e,a,b;
    scanf("%d%d",&v,&e);
    FOR(i,e)
    {
        scanf("%d%d",&a,&b);
        gr[a].pb(b);
        //gr[b].pb(a);  // enable it when the graph is bidirectional
    }
    FOR(i,v)
    {
        if(clr[i]==0)
            DFS(i);
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
