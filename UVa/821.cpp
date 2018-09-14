#include <bits/stdc++.h>
using namespace std;
#define bigval 1000000
int gr[102][102];

void FloydWarshal(int v)
{
    for(int k=1; k<=101; k++)
    {
        for(int i=1; i<=101; i++)
        {
            for(int j=1; j<=101; j++)
            {
                gr[i][j]=min(gr[i][j],gr[i][k]+gr[k][j]);
            }
        }
    }
}

void reset()

{
    for(int i=1; i<=101; i++)
    {
        for(int j=1; j<=101; j++)
        {
            if(i==j) gr[i][j]=0;
            else gr[i][j]=bigval;
        }
    }
}
int sum(int v)
{
    int ans=0;
    for(int i=1; i<=101; i++)
    {
        for(int j=1; j<=100; j++)
        {
            if(gr[i][j]==bigval)continue;
            else ans+=gr[i][j];
        }
    }
    return ans;
}
int main()
{
    //freopen("out.txt","w",stdout);
    reset();
    int v,e,a,b,edge,x=1;
    double res;
    while(scanf("%d%d",&v,&e)==2)
    {
        set<int>node;
        if(v==0&&e==0) break;
        gr[v][e]=1;
        node.insert(v);
        node.insert(e);

        while(1)
        {
            scanf("%d%d",&a,&b);
            if(a==0&&b==0) break;
            gr[a][b]=1;
            node.insert(a);
            node.insert(b);
        }
        int max_node=node.size();
        FloydWarshal(max_node);
        res = sum(max_node);
        res=res/(max_node*(max_node-1));
        printf("Case %d: average length between pages = %0.3lf clicks\n",x++,res);
        reset();
    }
    return 0;
}
