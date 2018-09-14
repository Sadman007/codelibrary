#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,n) for(int i=0;i<n;i++)

vector<int>gr[100010];
int clr[100010],t;
stack<int>topsort;

void DFS(int u)
{
    clr[u]=0;

    int gr_size=gr[u].size();
    FOR(i,gr_size)
    {
        int v=gr[u][i];
        if(clr[v]==0)
        {
            DFS(v);
        }

    }

    clr[u]=1;
    topsort.push(u);
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
    while(!topsort.empty())
    {
        cout << topsort.top() << endl;
        topsort.pop();
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
