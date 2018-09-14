#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,k,d,q,m;
int ara[400];
ll dp[202][100][11];

ll mod(ll a,ll b)
{
    return (a+b)%b;
}

ll solve(int idx,int sum,int freq)
{
    if(mod(sum,d)==0 && freq==m && idx<=n)
    {
        return 1LL;
    }
    if(idx>=n || freq>m) return 0LL;

    if(dp[idx][sum][freq]!=-1) return dp[idx][sum][freq];

    return dp[idx][sum][freq]=solve(idx+1,(sum+ara[idx])%d,freq+1)+solve(idx+1,sum,freq);

}

int main()
{
    //freopen("o.txt","w",stdout);
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++) scanf("%d",&ara[i]);
        printf("Case %d:\n",x);
        while(q--)
        {
            scanf("%d%d",&d,&m);
            memset(dp,-1,sizeof(dp));
            printf("%lld\n",solve(0,0,0));
        }
    }
    return 0;
}
