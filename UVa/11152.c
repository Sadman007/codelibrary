#include <stdio.h>

int main()
{
    double a,b,c;
    double s,area_bigc,big_r, small_r,area_t,sun,viol,ross;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        s=(a+b+c)/2;
        area_t=sqrt(s*(s-a)*(s-b)*(s-c));
        big_r=(a*b*c)/(4*area_t);
        small_r=area_t/s;
        ross=4*atan(1)*small_r*small_r;
        viol=area_t-ross;
        area_bigc=4*atan(1)*big_r*big_r;
        sun=area_bigc-area_t;
        printf("%.4lf %.4lf %.4lf\n",sun,viol,ross);
    }
    return 0;
}
