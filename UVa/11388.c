#include <stdio.h>

long long int gcd(long long int a,long long int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    long long int g,l,carry,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&g,&l);
        carry=gcd(g,l);
        if(carry==g) printf("%lld %lld\n",g,l);
        else printf("-1\n");
    }
    return 0;
}
