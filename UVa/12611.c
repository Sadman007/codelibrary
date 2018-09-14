#include <stdio.h>

int main()
{

    int x,t,i;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&x);

        printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n",i,(-9*x/4),(3*x/2),(11*x/4),(3*x/2),(11*x/4),(-3*x/2),(-9*x/4),(-3*x/2));

    }
    return 0;
}
