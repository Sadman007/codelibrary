#include<stdio.h>


int main()
{

    long long int n,ar[20],max,prod,cs=1,i,j;
    while(scanf("%lld",&n)==1)
    {
        max=0;
        for(i=0; i<n; i++)
            scanf("%lld",&ar[i]);
        for(i=0; i<n; i++)
        {
            prod=1;
            for(j=i; j<n; j++)
            {
                prod*=ar[j];
                if(prod>max)
                    max=prod;
            }
        }
        printf("Case #%lld: The maximum product is %lld.\n\n",cs++,max);
    }
    return 0;
}
