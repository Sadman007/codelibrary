#include <bits/stdc++.h>
using namespace std;
int dim=6,MOD;
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
    int q,t,n,num,a1,b1,c1,a2,b2,c2;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        mat f,ff;
        MOD=10;
        scanf("%d%d%d",&f.g[0][0],&f.g[0][1],&f.g[0][5]);
        scanf("%d%d%d",&f.g[3][3],&f.g[3][4],&f.g[3][2]);
        scanf("%d%d%d",&ff.g[2][0],&ff.g[1][0],&ff.g[0][0]);
        scanf("%d%d%d",&ff.g[5][0],&ff.g[4][0],&ff.g[3][0]);

        for(int i=1;i<dim;i++)
        {
            if(i!=3 && (i-1)!=2) f.g[i][i-1]=1;
        }
        printf("Case %d:\n",x);
        scanf("%d%d",&MOD,&q);
        while(q--)
        {
            scanf("%d",&num);
            mat first;
            first = power(f,num)*ff;

            printf("%d %d\n",first.g[2][0],first.g[5][0]);
        }
    }

    return 0;
}
