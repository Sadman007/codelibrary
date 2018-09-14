#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll modPow(ll a,ll b,ll MOD)
{
    if(b==0) return 1LL;
    if(b%2==0)
    {
        ll temp=modPow(a,b/2,MOD)%MOD;
        return (temp*temp)%MOD;
    }
    return (a*modPow(a,b-1,MOD))%MOD;
}

ll modInv(ll a,ll b)
{
    return modPow(a,b-2,b);
}

struct point
{
    int val,m;
};
point ara[14];

ll CRT(ll sz)
{
    ll x=0;
    ll M=1;
    for(int i=0; i<sz; i++)
    {
        M*=ara[i].m;
    }
    ll Midx[14];
    ll MInv[14];
    for(int i=0; i<sz; i++)
    {
        Midx[i]=M/ara[i].m;
        MInv[i]=modInv(Midx[i],ara[i].m);
    }
    for(int i=0; i<sz; i++)
    {
        x=(x+(ara[i].val*Midx[i]*MInv[i])%M)%M;
    }
    return x;
}

int main()
{
    int t,sz;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d",&sz);
        for(int i=0; i<sz; i++)
        {
            scanf("%d%d",&ara[i].m,&ara[i].val);
        }
        printf("Case %d: %lld\n",x,CRT(sz));
    }
    return 0;
}
