#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define boro_value 3000000000000
#define ll long long

int v,e,a,b,c;

struct edge
{
    int v;
    ll cost;
    edge() {};
    edge(int _v,ll _cost)
    {
        v=_v;
        cost=_cost;
    }
    bool operator< (const edge& a)const
    {
        return cost>a.cost;
    }
};

priority_queue< edge >pq;
vector<edge>gr[350];

ll d[350];
ll minPathLen[350];

void Dijkstra(int s)
{
    edge u;

    pq.push(edge(s,0));
    d[s]=0;

    while(!pq.empty())
    {
        u=pq.top();
        pq.pop();
        int sz = gr[u.v].size();

        for(int i=0; i<sz; i++)
        {
            int v=gr[u.v][i].v;

            if(d[u.v]+gr[u.v][i].cost < d[v])
            {
                d[v]=d[u.v]+gr[u.v][i].cost;
                pq.push(edge(v,d[v]));
                minPathLen[v] = minPathLen[u.v] + 1;
            }
            /// && minPathLen[v]>(minPathLen[u.v]+1)
            if(d[u.v]+gr[u.v][i].cost == d[v] && minPathLen[v]>(minPathLen[u.v]+1))
            {
                minPathLen[v] = minPathLen[u.v] + 1;
            }

        }
    }
}


int main()
{
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);

    scanf("%d%d",&v,&e);
    for(int i=0; i<e; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        gr[a].push_back(edge(b,c));
        gr[b].push_back(edge(a,c));
    }

    ll ans = 0;

    for(int node=1; node<=v; node++)
    {
        memset(d,31,sizeof d);
        memset(minPathLen,0,sizeof minPathLen);

        Dijkstra(node);

        for(int i=1; i<=v; i++)
        {
            if(i==node) continue;
            //printf("%d: %d  PATHLEN %d\n",i,d[i],minPathLen[i]);
            ans+=minPathLen[i];
        }
    }
    printf("%0.10f\n",1.0*ans/(v*(v-1)));

    return 0;
}
