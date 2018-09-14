#include <stdio.h>

long long LPD(long long n)
{   if(n<0) n=(-1)*n;
    long long i,cnt,mx=0,hishab=0;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            hishab++;
            cnt=0;
            while(n%i==0)
            {
                n=n/i;
                cnt++;
            }
        }
        if(i>mx) mx=i;
    }
    if(n>mx) { mx=n; hishab++; }
    if(hishab==1) return -1;
    return mx;
}

int main()
{
    long long n;

    while(scanf("%lld",&n)==1)
    {
        if(n==0) break;
        printf("%lld\n",LPD(n));
    }
    return 0;
}
