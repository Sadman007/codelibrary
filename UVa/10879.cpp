#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long T,n,i,cas=1,len,ara[4];
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        long long cou=0;
        len=(int) sqrt(n);
        for(i=2; i<=len; i++)
        {
            if(n%i==0)
            {
                ara[cou++]=i;
                ara[cou++]=n/i;
                if(cou==4) break;
            }

        }
        printf ("Case #%lld: %lld = %lld * %lld = %lld * %lld\n",cas++,n,ara[0],ara[1],ara[2],ara[3]);
    }
    return 0;
}
