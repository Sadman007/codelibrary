#include <stdio.h>

int main()
{

    long long int a,b,c,d,L,ans,x,cnt=0;
    while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&L)==5){
    if(a==0&&b==0&&c==0&&d==0&&L==0) break;
    for(x=0; x<=L; x++)
    {
        ans=(a*x*x)+(b*x)+(c);
        if(ans%d==0)
        {
            cnt=cnt+1;
        }

    }

    printf("%lld\n",cnt);
    cnt=0;
        }
    return 0;
}
