#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define boro_value 100000000
int v,e,a,b,c;

struct node
{
    int v,cost;

    bool operator< (const node& a)const
    {
        return cost<a.cost;
    }
    bool operator> (const node& a)const
    {
        return cost>a.cost;
    }
};

priority_queue< node, vector<node>, greater<node> >pq;
vector<int>gr[300010];
vector<int>cost[300010];
stack<int>path;
int pre[300010],d[300010];


void prim(int s)
{
    node t1,t2,t3;
    t1.v=s,t1.cost=0;
    pq.push(t1);
    d[s]=0;

    while(!pq.empty())
    {
        t1=pq.top();
        pq.pop();
        int u=t1.v;

        for(int i=0; i<gr[u].size(); i++)
        {
            int v=gr[u][i];
            if(cost[u][i] < d[v] && pre[u]!=v && u!=v)
            {
                d[v]=cost[u][i];
                pre[v]=u;
                t3.v=v;
                t3.cost=d[v];
                pq.push(t3);
            }
        }
    }
}

int main()
{
    scanf("%d%d",&v,&e);
    for(int i=0; i<e; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        gr[a].pb(b);
        gr[b].pb(a);
        cost[a].pb(c);
        cost[b].pb(c);
    }
    for(int i=0; i<300010; i++)
    {
        d[i]=boro_value;
    }
    prim(0);
    int ans=0;
    for(int i=0; i<v; i++)
    {
        ans+=d[i];
    }
    printf("%d\n",ans);
    return 0;
}
