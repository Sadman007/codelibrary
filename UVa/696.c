#include <stdio.h>

double knight(double m,double n)
{
    int t,a,b;
    if(m>n)
    {
        t=m;
        m=n;
        n=t;
    }
    if(m==1) return n;
    if(m==2) return 2*(ceil(n/4)+ceil((n-1)/4));
    else return ceil((m*n)/2);
}

int main()
{
    double a,b;
    while(scanf("%lf%lf",&a,&b)==2)
    {
        if(a==0.00&&b==0.00) break;
        printf("%.lf knights may be placed on a %.lf row %.lf column board.\n",knight(a,b),a,b);
    }
    return 0;
}
