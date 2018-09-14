#include <stdio.h>

int main()
{
    int a1,a2,b1,b2,c1,c2;
    int x1,x2,x3,x4,yb,y2,y3,y4;
    double x,y,k;
    int t;
    scanf("%d",&t);
    printf("INTERSECTING LINES OUTPUT\n");
    while(t--)
    {

        scanf("%d%d%d%d%d%d%d%d",&x1,&yb,&x2,&y2,&x3,&y3,&x4,&y4);
        a1=y2-yb;
        b1=x1-x2;
        c1=x1*y2-x2*yb;

        a2=y4-y3;
        b2=x3-x4;
        c2=x3*y4-x4*y3;

        x=(b2*c1-b1*c2)*1.0/(a1*b2-a2*b1)*1.0;
        y=(a1*c2-a2*c1)*1.0/(a1*b2-a2*b1)*1.0;

        k=(a1*1.0)/(a2*1.0);

        if(k*b2==b1&&k*c2==c1)
        {
            printf("LINE\n");
            continue;
        }
        int ans=a1*b2-a2*b1;
        if(ans==0)
        {
            printf("NONE\n");
            continue;
        }
        printf("POINT %0.2lf %0.2lf\n",x,y);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
