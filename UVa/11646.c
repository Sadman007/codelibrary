#include <stdio.h>
#include <math.h>

int main() {

    double t=1,a,b,x;
    while(scanf("%lf : %lf",&a,&b)==2) {

        x=200/(atan(b/a)*(sqrt(a*a+b*b))+a);

        printf ("Case %0.lf: %0.10lf %0.10lf\n",t++,a*x,b*x);
    }
return 0;

}
