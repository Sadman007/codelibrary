#include <stdio.h>
#include <math.h>

int main()
{
    int T, i=1;
    scanf("%d",&T);
    for (i=1; i<=T; i++)
    {

        double r1,r2,r3;
        scanf ("%lf%lf%lf",&r1,&r2,&r3);

        double s,area;
        s=r1+r2+r3;
        area=sqrt(s*(s-r1-r2)*(s-r2-r3)*(s-r1-r3));

        double a,b,c,A,B,C,area2;
        a = r1+r2;
        b = r2+r3;
        c = r3+r1;

        A = acos ((b*b+c*c-a*a)/(2*b*c));
        B = acos ((a*a+c*c-b*b)/(2*a*c));
        C = acos ((b*b+a*a-c*c)/(2*b*a));

        area2 = area - (0.5*((A*r3*r3)+(B*r1*r1)+(C*r2*r2)));

        printf ("%0.6lf\n",area2);

    }
    return 0;
}
