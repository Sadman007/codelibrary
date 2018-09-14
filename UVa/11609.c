#include <stdio.h>
#define mod 1000000007
long long int combination(long long int b,long long int p)
{
    if(p==0) return 1;
    if(p==1) return b;
    long long int x;
    if(p%2==0)
    {
        x=combination(b,p/2)%mod;
        return (x*x)%mod;
    }
    else return (combination (b,p-1)%mod)*(b%mod);
}

int main()
{
    long long int n,c,i;
    scanf("%lld",&c);
    for(i=1; i<=c; i++)
    {
        scanf("%lld",&n);
        printf("Case #%lld: %lld\n",i,((combination (2, n - 1) * (n % mod)) % mod));
    }
    return 0;
}
