#include <bits/stdc++.h>
using namespace std;
#define MAX 10010

struct node
{
    int w,use,v;

    bool operator <(const node& a)const
    {
        return w<a.w;
    }
    bool operator >(const node& a)const
    {
        return w>a.w;
    }
};

vector<node>gr[MAX+10];
int dist[MAX+10][11];

int Dijkstra(int st,int en,int limit)
{
    priority_queue< node, vector<node>, greater<node> >pq;
    int ans = 0x3f3f3f3f;

    pq.push({0,0,st});
    memset(dist,0x3f3f3f3f,sizeof(dist));

    dist[st][0]=0;

    while(!pq.empty())
    {
        node v = pq.top();
        pq.pop();

        int from,used;
        from = v.v;
        used = v.use;

        int sz = gr[from].size();

        for(int i=0;i<sz;i++)
        {
            int jabo,use_korbo,khoroch;

            jabo = gr[from][i].v;

            use_korbo = gr[from][i].use;

            khoroch = gr[from][i].w;

            if(used + use_korbo > limit) continue;

            if(dist[jabo][used+use_korbo] > dist[from][used]+khoroch)
            {
                dist[jabo][used+use_korbo] = dist[from][used]+khoroch;
                pq.push({dist[jabo][used+use_korbo],used+use_korbo,jabo});
            }
        }

    }

    for(int i=0;i<=limit;i++)
    {
        if(dist[en][i] < ans) ans=dist[en][i];
    }
    for(int i=0;i<MAX;i++) gr[i].clear();
    return ans;
}


int main()
{

    int T;
    scanf("%d",&T);
    for(int x=1;x<=T;x++)
    {
        int v,e,prop,lim;
        scanf("%d%d%d%d",&v,&e,&prop,&lim);

        for(int i=0;i<e;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            gr[a].push_back({c,0,b});
        }
        for(int i=0;i<prop;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            gr[a].push_back({c,1,b});
        }
        int res = Dijkstra(0,v-1,lim);
        if(res==0x3f3f3f3f) printf("Case %d: Impossible\n",x);
        else printf("Case %d: %d\n",x,res);
    }
    return 0;
}
