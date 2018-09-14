#include <stdio.h>

int main()
{
    long long int a,b,c,d;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3)
    {
        if(a==0&&b==0&&c==0) break;
        d=((a-7)*(b-7));
        if(d%2!=0&&c==1) printf("%lld\n",(d/2)+1);
        else printf("%lld\n",d/2);
    }
    return 0;
}
