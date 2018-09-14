#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD;
#define SZ 21

struct mat
{
    ll r, c, g[SZ][SZ];

    mat()
    {
        r = c = SZ;
        memset(g,0,sizeof(g));
    }

    mat operator * (mat b)
    {
        ll p;
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

    void Iden()
    {
        for(int i=0; i<20; i++)
        {
            for(int j=0; j<20; j++)
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

int main()
{
    //freopen("o.txt","w",stdout);

    ll n,d;
    while(scanf("%lld%lld%lld",&d,&n,&MOD)==3)
    {
        if(d==0 && n==0 && MOD==0) break;
        mat a,b,c;
        for(int i=0; i<d; i++)
        {
            scanf("%lld",&a.g[0][i]);
        }
        for(int i=0; i<d; i++)
        {
            a.g[i+1][i]=1;
        }
        for(int i=0; i<d; i++)
        {
            scanf("%lld",&b.g[d-i-1][0]);
        }
        c = power(a,n-d)*b;

        printf("%lld\n",c.g[0][0]%MOD);
    }
    return 0;
}
