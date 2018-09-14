#include <bits/stdc++.h>
using namespace std;
double a[10000000];

void sieve()
{
    int i;
    a[1]=0;
    for(i=2; i<=10000000; i++) a[i]=a[i-1]+log10(i);
}

int main()
{
    sieve();
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",(int)a[n]+1);
    }
    return 0;
}
