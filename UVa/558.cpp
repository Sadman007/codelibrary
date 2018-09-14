#include <bits/stdc++.h>
using namespace std;

struct info
{
    int a,b,cost;
} gr[2050];
int d[2050];
int V,E;
bool cycle;
void BellmanFord(int s,int des)
{
    d[s]=0;
    cycle=false;
    int i;
    for(i=1; i<V; i++)
    {
        for(int j=0; j<E; j++)
        {
            d[gr[j].b]=min(d[gr[j].b],d[gr[j].a]+gr[j].cost);
        }
    }
    for(int j=0; j<E; j++)
    {
        if(d[gr[j].b]>d[gr[j].a]+gr[j].cost)
            cycle=true;
    }

}

void reset()
{
    memset(d,127,sizeof(d));
}
int main()
{
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        reset();
        int a,b,c;
        scanf("%d%d",&V,&E);
        for(int i=0; i<E; i++)
        {
            scanf("%d%d%d",&gr[i].a,&gr[i].b,&gr[i].cost);
        }
        BellmanFord(0,0);
        if(cycle) printf("possible\n");
        else printf("not possible\n");
    }
}
