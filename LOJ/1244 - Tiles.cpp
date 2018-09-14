#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 10007
#define SZ 4


struct mat
{
    int r, c, g[SZ][SZ];

    mat()
    {
        r = c = 4;
        memset(g,0,sizeof(g));
    }

    mat operator * (mat b)
    {
        int p;
        mat res;
        res.r = r ;
        res.c = b.c;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<b.c; j++)
            {
                p = 0;
                for(int k=0; k<c; k++)
                    p= (p+(g[i][k]*b.g[k][j]))%MOD;
                res.g[i][j] = (p%MOD);
            }
        }
        return res;
    }
    mat operator + (mat b) // for square matrices
    {
        mat res;
        res.r = r;
        res.c = c;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                res.g[i][j]=(g[i][j]%MOD+b.g[i][j]%MOD)%MOD;
            }
        }
        return res;
    }
    mat operator - (mat b) // for square matrices
    {
        mat res;
        res.r = r;
        res.c = c;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                res.g[i][j]=(g[i][j]%MOD-b.g[i][j]%MOD)%MOD;
            }
        }
        return res;
    }


    void Iden()
    {
        for(int i=0; i<SZ; i++)
        {
            for(int j=0; j<SZ; j++)
            {
                g[i][j] = (i==j);
            }
        }
    }

};

mat bigMod(mat a, int n )
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
int main()
{
    int t;
    scanf("%d",&t);
    for(int x=1;x<=t;x++)
    {
        int n;
        scanf("%d",&n);
        mat tmp;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++) tmp.g[i][j]=1;
        }
        tmp.g[1][1] = 0;
        tmp.g[1][2] = 0;
        tmp.g[1][3] = 0;
        tmp.g[2][0] = 0;
        tmp.g[2][2] = 0;
        tmp.g[3][0] = 0;
        tmp.g[3][3] = 0;

        tmp = bigMod(tmp,n);

        printf("Case %d: %d\n",x,tmp.g[0][0]);
    }
}


