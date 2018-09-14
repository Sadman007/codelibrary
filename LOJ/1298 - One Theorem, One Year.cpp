#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAX 3572
ll dp[510][510],mul_prime[MAX+10],n,k;
vector<ll>prime;
bool primes[MAX+10];

void sieve()
{
    prime.push_back(2);
    for(int i=2; i<=MAX; i+=2) primes[i]=true;
    for(int i=3; i<=MAX; i++)
    {
        if(!primes[i])
        {
            prime.push_back(i);
            for(int j=i+i; j<=MAX; j+=i) primes[j]=true;
        }
    }

    mul_prime[0]=1;
    for(int i=1; i<prime.size(); i++)
    {
        mul_prime[i] = (mul_prime[i-1]%mod*(prime[i]-1)%mod)%mod;
    }
    return;
}

ll solve(ll indx, ll left)
{
    if(left == 0) return 1;
    if(indx < 0) return 0;
    if(dp[indx][left] != -1) return dp[indx][left]%mod;

    return dp[indx][left] = ((prime[indx]*solve(indx, left-1))%mod + solve(indx-1, left)%mod)%mod;
}

int main()
{
    sieve();
    memset(dp,-1,sizeof(dp));

    int t;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%lld%lld",&n,&k);
        ll ans  = mul_prime[k-1]%mod;

        int rem=n-k;
        if(rem==0) printf("Case %d: %lld\n",x,ans);
        else
        {
            ll ans2 = solve(k-1,rem)%mod;
            printf("Case %d: %lld\n",x,abs((ans*ans2)%mod));
        }
    }
    return 0;
}
