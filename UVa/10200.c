#include <stdio.h>
long long int a[100000],b[10000];

long long int prime(long long int a)
{
    long long int i;
    for(i=2; i*i<=a; i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    long long int x,y,i,j,count,p;
    a[0]=a[1]=1;
    for(i=4; i<100000; i=i+2)
    {
        a[i]=1;
    }
    for(i=3; i<100000; i=i+2)
    {
        if(a[i]==0)
            for(j=i*i; j<100000; j=j+i)
                a[j]=1;
    }
    b[0]=0,b[1]=1,j=0;
    for(i=2; i<100000; i++)
    {
        if(prime(i)==0) b[j++]=i;
    }
    while(scanf("%lld%lld",&x,&y)==2)
    {
        count=0;
        p=y-x+1;
        double step1;
            for(i=x; i<=y; i++)
            {
                p=i*i+i+41;
                if(a[p]==0) count++;

            }
            if(p==count) printf("100.00\n");

        else
        {
            step1=(count*1.0/p)*100.0;
            printf("%0.2lf\n",step1);

        }
        }

    return 0;
}
