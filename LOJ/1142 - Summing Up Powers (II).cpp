#include <bits/stdc++.h>
using namespace std;
int dim;
#define MOD 10
#define SZ 31

struct mat
{
    int r, c, g[SZ][SZ];

    mat()
    {
        r = c = SZ;
        memset(g,0,sizeof(g));
    }

    mat operator * (mat b)
    {
        int p;
        mat res;
        res.r = dim;
        res.c = dim;
        for(int i=0; i<dim; i++)
        {
            for(int j=0; j<dim; j++)
            {
                p = 0;
                for(int k=0; k<dim; k++)
                    p= (p+(g[i][k]*b.g[k][j]))%MOD;
                res.g[i][j] = (p%MOD);
            }
        }
        return res;
    }
    mat operator + (mat b)
    {
        mat res;
        res.r = dim;
        res.c = dim;

        for(int i=0; i<dim; i++)
        {
            for(int j=0; j<dim; j++)
            {
                res.g[i][j]=(g[i][j]%MOD+b.g[i][j]%MOD)%MOD;
            }
        }
        return res;
    }

    void Iden()
    {
        for(int i=0; i<dim; i++)
        {
            for(int j=0; j<dim; j++)
            {
                g[i][j] = (i==j);
            }
        }
    }

};
mat power(mat a, int n )
{
    mat r,p;
    r.Iden() ;
    p = a;
    while(n)
    {
        if(( n & 1 )==1) r = r * p;
        p = p * p;
        n >>= 1;
    }
    return r;
}

mat func(mat base,int n)
{
    if(n==1) return power(base,n);

    if(n%2==0)
    {
        mat temp=func(base,n/2);
        return (temp+(power(base,n/2)*temp));
    }
    return (power(base,n)+func(base,n-1));
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d %d",&dim,&n);
        mat b,res;

        for(int i=0; i<dim; i++)
        {
            for(int j=0; j<dim; j++)
            {
                scanf("%d",&b.g[i][j]);
            }
        }

        res = func(b,n);
        printf("Case %d:\n",x);
        for(int i=0; i<dim; i++)
        {
            for(int j=0; j<dim; j++)
            {
                printf("%d",res.g[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
