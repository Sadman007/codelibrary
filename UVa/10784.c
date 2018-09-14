#include <stdio.h>
#include <math.h>

int main(){
    int kase=1;
    double n,k;


while (scanf ("%lf",&k)==1) {
        if (k==0)
        break;

    n=sqrt((2*k)+2.25)+1.5;
    printf ("Case %d: %0.lf\n",kase,ceil(n));
    kase++;

}
    return 0;


}
