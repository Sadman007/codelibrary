#include <stdio.h>
#include <math.h>

int main() {
    double p,n,ans;
    while(scanf ("%lf%lf",&n,&p)==2){

    ans=pow(p,(1/n));

    printf ("%0.lf\n",ans);

    }

    return 0;

}
