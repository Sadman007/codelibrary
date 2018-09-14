#include <stdio.h>
#include <math.h>

int main() {

    double a,b,a1,a2,pi=acos(-1.0);
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%lf",&a);
        b=(3.0*a)/5.0;
        a1=(pi*a*a)/25.0;
        a2=((3.0*a*a)/5.0)-a1;
        printf ("%.2lf %.2lf\n",a1,a2);
    }
return 0;
}
