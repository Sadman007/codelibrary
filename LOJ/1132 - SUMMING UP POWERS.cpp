#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int

ui nCr[55][55];
//ll MOD=2147483648*2;
#define SZ 53

void precalc()
{
    for(int i=0; i<52; i++) nCr[i][0]=1;
    for(int i=1; i<52; i++)
    {
        for(int j=1; j<=i; j++) nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j]);
    }
    return;
}



struct mat
{
    ll r, c;
    ui g[SZ][SZ];

    mat()
    {
        r = c = SZ;
        memset(g,0,sizeof(g));
    }

    mat operator * (mat b)
    {
        ui p;
        mat res;
        res.r = r ;
        res.c = b.c;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<b.c; j++)
            {
                p = 0;
                for(int k=0; k<c; k++)
                    p+=g[i][k]*b.g[k][j];
                res.g[i][j] = p;
            }
        }
        return res;
    }



    void Iden(int len)
    {
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len; j++)
            {
                g[i][j] = (i==j);
            }
        }
    }
};


mat bigMod(mat a, ll n )
{
    mat r,p;
    r.Iden(r.c) ;
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
    // freopen("o.txt","w",stdout);
    precalc();
    mat a,b,c;
    int t;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        long long n,k;
        ui ans;
        scanf("%lld%lld",&n,&k);
        if(n==1) ans=1;
        else
        {
            a.r=a.c=k+2;
            b.r=c.r=k+2;
            b.c=c.c=1;

            for(int j=0; j<(a.c); j++)
            {
                if(j<1) a.g[0][j]=1;
                else a.g[0][j]=nCr[k][j-1];

                b.g[j][0]=1;
            }
            for(int i=1; i<(a.r); i++)
            {
                int m=0;
                for(int j=0; j<(a.c); j++)
                {
                    if(j<i) a.g[i][j]=0;
                    else a.g[i][j]=nCr[k-i+1][m++];
                }
            }
            c=bigMod(a,n-1)*b;
            ans=c.g[0][0];
            printf("Case %d: %u\n",x,ans);
        }
    }
    return 0;
}
