#include <bits/stdc++.h>
using namespace std;
#define N 5050
#define K 2

struct edge
{
    int vtx,cost;
    edge() {};
    edge(int _vtx,int _cost)
    {
        vtx=_vtx;
        cost=_cost;
    }
    bool operator<(const edge &a) const
    {
        return cost>a.cost;
    }
};

priority_queue<edge>pq;
vector <edge> vc[N];
vector <int> dist[N];

void Dijkstra(int st)
{
    edge curr;
    for(int i=0; i<N; i++) dist[i].clear();
    while(!pq.empty()) pq.pop();

    pq.push(edge(st,0));

    while(!pq.empty())
    {
        curr=pq.top();
        pq.pop();

        if(dist[curr.vtx].size()==0) dist[curr.vtx].push_back(curr.cost); // curr.to has never been visited before!
        else if(dist[curr.vtx].back()!=curr.cost) dist[curr.vtx].push_back(curr.cost); // it's been relaxed one time. Doing it again for next shortest paths

        if(dist[curr.vtx].size()>K) continue; // we have 2 best shortest paths. No need to check again.

        for(int i=0; i<vc[curr.vtx].size(); i++)
        {
            if(dist[vc[curr.vtx][i].vtx].size()==K) continue; // we have 2 best shortest paths. No need to check again.

            int current_dist = vc[curr.vtx][i].cost+curr.cost;
            pq.push(edge(vc[curr.vtx][i].vtx,current_dist));
        }
    }
}

void CLR()
{
    for(int i=0; i<N; i++) vc[i].clear();
}



int main()
{
    int t,v,e,a,b,c;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        CLR();
        scanf("%d%d",&v,&e);
        for(int i=0; i<e; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            --a;
            --b;
            vc[a].push_back(edge(b,c));
            vc[b].push_back(edge(a,c));
        }
        Dijkstra(0);
        printf("Case %d: %d\n",x,dist[v-1][K-1]);
    }
    return 0;
}
