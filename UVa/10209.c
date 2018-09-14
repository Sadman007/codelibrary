#include <stdio.h>
#include <math.h>


int main() {
    double a;
    while(scanf ("%lf",&a)==1) {

    double pi;
    pi=acos(-1);

    double x,y,z;
    x= a*a*(1-sqrt(3)+(pi/3));
    y= a*a*((2*sqrt(3))-4+(pi/3));
    z= a*a*(4-sqrt(3)-(2*pi/3));

    printf ("%0.3lf %0.3lf %0.3lf\n",x,y,z);

    }

    return 0;

}
