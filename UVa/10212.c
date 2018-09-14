#include <stdio.h>

int main()
{
    long long n,r,ans,i;
    while(scanf("%lld%lld",&n,&r)==2)
    {
        ans=1;
        for(i=n; i>(n-r); i--)
        {
            ans*=i;
            while(ans%10==0)
            {
                ans/=10;
            }
            if(ans>=1000000000) ans=ans%1000000000;
        }
        printf("%lld\n",ans%10);
    }
    return 0;
}
