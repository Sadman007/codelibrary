#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000
ll dp[220][220];
ll slv()
{
    memset(dp,0,sizeof(dp));
    for(int i=0; i<220; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0||j==i) dp[i][j]=1;
            else dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
        }
    }
}
int main()
{
    //freopen("o.txt","w",stdout);
    ll n,k;
    slv();
    while(scanf("%lld%lld",&n,&k)==2 && n!=0 && k!=0)
    {
        printf("%lld\n",dp[n+k-1][k-1]);
    }
    return 0;
}

