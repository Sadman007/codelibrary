#include<stdio.h>
long long int counter(long long int a)
{
    long long int sum=0;

    while(a>0)
    {
        sum+=a%10;
        a/=10;
    }
    return sum;
}

int main()
{
    long long int a,b,i,sum;
    while(scanf("%lld",&a)==1)
    {
        if(a==0) break;
        sum=counter(a);
        while(sum>9)
        {
            sum=counter(sum);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
