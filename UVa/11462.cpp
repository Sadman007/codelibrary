#include <stdio.h>
#include <algorithm>
long long int aray[2000010];
using namespace std;
int main()
{
    long long int i,j,n;
    while(scanf("%lld",&n)==1 && n!=0)
    {
        for(i=0; i<n; i++)
            scanf("%lld",&aray[i]);
        sort(aray,aray+n);
        for(i=0; i<n-1; i++)
            printf("%lld ",aray[i]);
            printf("%lld\n",aray[n-1]);
    }
    return 0;
}
