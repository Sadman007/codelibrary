#include <stdio.h>
#include <math.h>

#define pi acos(-1)

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double L,D;
        scanf("%lf%lf",&D,&L);
        printf("%0.3lf\n",pi*L*(sqrt(L*L-D*D)/4.0));
    }
    return 0;
}
