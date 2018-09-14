#include <stdio.h>

int main()
{
    long long n;
    while(1)
    {
        scanf("%lld",&n);
        if(n<3) break;
        printf("%lld\n",n*(n-2)*(2*n-5)/24);
    }
    return 0;
}
