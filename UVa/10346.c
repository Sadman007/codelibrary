#include <stdio.h>

int main()
{
    int n,k;
    while ((scanf ("%d %d",&n,&k))!= EOF) {

    int a,f;
    a = (n-1)/(k-1);
    f = n + a;

    printf ("%d\n",f);
    }
    return 0;
    }
