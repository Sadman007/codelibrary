#include <stdio.h>

void primeFactors(long long int n)
{
    long long int i;
    if(n<0) n=(-1)*n;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
                if(n!=1)
                    printf("%lld x ",i);
                if(n==1)
                    printf("%lld\n",i);
            }
        }
    }
    if(n!=1) printf("%lld\n",n);
}

int main()
{
    long long int n;
    while(scanf("%lld",&n)==1)
    {
        if(n==0) break;
        printf("%lld = ",n);
        if(n<0) printf("-1 x ");
        primeFactors(n);
    }
    return 0;
}
