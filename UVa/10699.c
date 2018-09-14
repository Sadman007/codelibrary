#include <stdio.h>

int main()
{

    long long int a,i,h,count,flag,save;

    while(scanf("%lld",&a)==1)
    {   save=a;
        if(a==0) break;
        count=0;
        for(i=2; i<=a; i++)
        {
            if(a%i==0)
            {
                while(a%i==0)
                {
                    a/=i;
                    flag=1;
                }
                if(flag==1) count++;
            }
        }

        printf("%lld : %lld\n",save,count);
    }
    return 0;
}
