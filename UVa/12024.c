#include <stdio.h>

int main()
{
    int D[12]= {0,1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841};
    int fact[12]= {1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};

    int i,n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d/%d\n",D[n-1],fact[n-1]);
    }
    return 0;
}