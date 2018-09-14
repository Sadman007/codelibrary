#include <stdio.h>

int main()
{

    long long int n,p;
    while(scanf("%lld",&n)==1)
    {
        if(n==1) printf("3\n");
        else
        {
            p=(n+1)/2;
            printf("%lld\n",6*p*p-9);
        }
    }
    return 0;
}
