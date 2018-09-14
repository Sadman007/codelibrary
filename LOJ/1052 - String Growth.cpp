#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dim=2,MOD=1000000007;
#define SZ 31

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
        res.r = dim;
        res.c = dim;
        for(int i=0; i<dim; i++)
        {
            for(int j=0; j<dim; j++)
            {
                p = 0;
                for(ll k=0; k<dim; k++)
                {
                    p= (p+(g[i][k]*b.g[k][j]));
                    if(p>=MOD) p%=MOD;
                }

                res.g[i][j] = (p);
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
mat power(mat a, ll n )
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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll q,t,n,num,a1,b1,c1,a2,b2,c2;
    scanf("%lld",&t);
    for(int x=1; x<=t; x++)
    {
        mat fmat;
        mat fib,base;

        fib.g[0][0]=1;
        fib.g[0][1]=1;
        fib.g[1][0]=1;
        fib.g[1][1]=0;

        base.g[0][0]=1;
        base.g[1][0]=0;

        ll nth,mth,fm,fn,kth;
        scanf("%lld%lld%lld%lld%lld",&nth,&fn,&mth,&fm,&kth);

        ll a1,b1,c1,a2,b2,c2;
        c1=fn;
        c2=fm;

        a1=(power(fib,nth)*base).g[1][0];
        b1=(power(fib,nth+1)*base).g[1][0];

        a2=(power(fib,mth)*base).g[1][0];
        b2=(power(fib,mth+1)*base).g[1][0];

        ll ans;
        ll D=(a1*b2)-(a2*b1);
        ll na,nb;

        na = b2*c1-b1*c2;
        nb = a1*c2-a2*c1;

        bool impo=false;
        cout<<D<<" "<<na<<" "<<nb<<endl;
        int tx;
        int komabo=0;
        while(na<0 || nb<0)
        {
            tx=na+nb;
            na=nb;
            nb=tx;
            komabo++;
        }
        if(na%D!=0 || nb%D!=0 || D==0)
        {
            printf("Case %d: Impossible\n",x);
            continue;
        }

        na/=D;
        nb/=D;

        if(na<0 || nb<0)
        {
            printf("Case %d: Impossible\n",x);
            continue;
        }


        base.g[0][0]=nb;
        base.g[1][0]=na;

        ans=(power(fib,kth+1-komabo)*base).g[1][0];

        printf("Case %d: %lld\n",x,ans%MOD);

    }

    return 0;
}
