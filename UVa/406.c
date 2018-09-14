#include <stdio.h>

long long int prime(long long int a)
{
    long long int i;
    if(a==0) return 1;
    if(a==1) return 0;
    for(i=2; i*i<=a; i++)
    {
        if(a%i==0) return 1;
    }
    return 0;
}

int main()
{

    long long int a,c,aa,cc,i,count,ara[1000],j;
    while(scanf("%lld%lld",&a,&c)==2)
    {
        i=0,j=0;
        aa=a;
        cc=c;
        for(i=1; i<=a; i++)
        {
            if(prime(i)==0) ara[j++]=i;
        }
        j=j-1;
        if(j%2==0) c=c-1;
        else c=c;

        long long int mid=(j/2),start,end;
        if(mid<c)
        {
            printf("%lld %lld: ",aa,cc);
            for(i=0; i<j; i++) printf("%lld ",ara[i]);
            printf("%lld\n\n",ara[i]);
        }
        else
        {
            start=mid-c;
            end=mid+c;
            if(j%2!=0) start++;
            printf("%lld %lld: ",aa,cc);
            for(i=start; i<end; i++)
            {
                printf("%lld ",ara[i]);
            }
            printf("%lld\n\n",ara[i]);
        }
    }
    return 0;
}
