#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
int pr[MAX],val[MAX];
int n,m,q;
int sparseTb[MAX][20];
int MAX_DEPTH;

void buildSpTb()
{
    memset(sparseTb,-1,sizeof sparseTb);
    for(int i=0; i<n; i++) sparseTb[i][0] = pr[i];

    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=1; i<n; i++)
        {
            if(sparseTb[i][j-1]!=-1)
                sparseTb[i][j] = sparseTb[sparseTb[i][j-1]][j-1];
        }
    }
}

int query(int k,int v)
{
    for(int i=MAX_DEPTH; i>=0; i--)
    {
        if(sparseTb[k][i]!=-1 && val[sparseTb[k][i]]>=v)
            k = sparseTb[k][i];
    }
    return k;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int p,v,k;
        scanf("%d%d",&n,&q);
        MAX_DEPTH = (int)log2(n);

        pr[0] = 0;
        val[0] = 1;

        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&p,&v);
            pr[i] = p;
            val[i] = v;
        }
        buildSpTb();
        printf("Case %d:\n",cs++);
        for(int i=0; i<q; i++)
        {
            scanf("%d%d",&k,&v);
            printf("%d\n",query(k,v));
        }
    }
    return 0;
}
