/**
        *   Lets think about the second sample test. The very basic combination is J1 J1 J2 J2 J3 J3 J3.
        *   If we consider one job, then there would be one combination: J1 J1.
        *   If we add the second job, then very basic combination would be: J1 J1 J2 J2. Here, Last J2
        *   is not movable. So, without it, there are 3 elements. but 2 of them are same. So, 3!/2! would
        *   be multiplied by the previous result.
        *   If we add the third job, then very basic combination would be: J1 J1 J2 J2 J3 J3 J3. Here,
        *   Last J3 is not movable. So, without it, there are 6 elements. but 2 of them are same and 4 of
        *   them are calculated in the previous step. So, 6!/(2!*4!) would be multiplied by the previous
        *   result which is the final result. In this way, other cases could be calculated.
        */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll ara[1005];
ll fact[1000010];
void pre()
{
    fact[0]=1;
    for(int i=1;i<=1000001;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }
    return;
}

ll po(ll a,ll b)
{
    if(b==0) return 1LL;
    if(b%2==0)
    {
        ll t = po(a,b/2)%MOD;
        return (t%MOD*t%MOD)%MOD;
    }
    return (a%MOD*po(a,b-1)%MOD)%MOD;
}


int main()
{
    pre();
    int T;
    scanf("%d",&T);
    for(int x=1; x<=T; x++)
    {
        ll tmp3,tmp1,tmp2,ans=1,total;
        int n;
        scanf("%d",&n);

        scanf("%d",&ara[0]);
        total = ara[0];

        for(int i=1; i<n; i++)
        {
            scanf("%d",&ara[i]);

            tmp1 = fact[total+ara[i]-1]%MOD;
            tmp2 = po(fact[ara[i]-1],MOD-2)%MOD;
            tmp3 = po(fact[total],MOD-2)%MOD;

            ans = (ans*tmp1)%MOD;
            ans = (ans*tmp2)%MOD;
            ans = (ans*tmp3)%MOD;

            total+=ara[i];
        }

        printf("Case %d: %lld\n",x,ans);

    }
    return 0;
}
