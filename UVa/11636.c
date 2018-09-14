#include <stdio.h>
#include <math.h>

int main() {
    double a;
    int n=1;
    while(scanf ("%lf",&a)==1){
        if (a<0) break;
        double p,ans,a1,a2;
        a1=log(a);
        a2=log(2);
        ans=a1/a2;

printf ("Case %d: %0.lf\n",n++,ceil(ans));
    }
return 0;
}
