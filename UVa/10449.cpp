#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,cost;
} gr[10000];
int d[10000],v,e;

void BellmanFord(int s)
{
    d[s]=0;
    for(int i=1; i<v; i++)
    {
        for(int j=0; j<e; j++)
        {
            d[gr[j].v]=min(d[gr[j].v],d[gr[j].u]+gr[j].cost);
        }
    }
}

int po(int a,int b)
{
    int s=1;
    while(b--) s*=a;
    return s;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int a,b,queries,c,x=1;
    int cba[10000];
    while(scanf("%d",&v)==1)
    {
        memset(gr,0,sizeof(gr));
        for(int i=0; i<v; i++)
        {
            scanf("%d",&cba[i]);
        }
        scanf("%d",&e);
        for(int i=0; i<e; i++)
        {
            cin >> a >> b;
            node t;
            t.u=a-1;
            t.v=b-1;
            t.cost=po((cba[t.v]-cba[t.u]),3);
            gr[i]=t;
        }

        memset(d,-129,sizeof(d));
        BellmanFord(0);

        scanf("%d",&queries);
        printf("Set #%d\n",x++);

        for(int i=0; i<queries; i++)
        {
            scanf("%d",&v);
            if(d[v-1]<3 || d[v-1]>99999999) printf("?\n");
            else
            {
                int d_past=d[v-1],d_new;
                for(int j=0; j<e; j++)
                {
                    d[gr[j].v]=min(d[gr[j].v],d[gr[j].u]+gr[j].cost);
                }
                d_new=d[v-1];
                if(d_past>d_new) printf("?\n");
                else printf("%d\n",d[v-1]);
            }
        }
    }
    return 0;
}
