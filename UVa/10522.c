#include <stdio.h>
#include <math.h>

int main() {

    int t, test;
    double Ha,Hb,Hc;
    double a,b,c,d,e;
    scanf("%d", &test);
    t=0;
    while(t!=test) {


    scanf ("%lf%lf%lf",&Ha,&Hb,&Hc);

    if (Ha<=0||Hb<=0||Hc<=0){
        printf ("These are invalid inputs!\n");
        t++;
        continue;
    }


    a= (1/Ha)+(1/Hb)+(1/Hc);
    b= (1/Ha)+(1/Hb)-(1/Hc);
    c= (1/Hc)+(1/Hb)-(1/Ha);
    d= (1/Ha)+(1/Hc)-(1/Hb);

    e= a*b*c*d;


    if (e<0) {

        printf ("These are invalid inputs!\n");
        t++;
    }


    else {
    printf ("%0.3lf\n",sqrt(1/e));

    }
    }
    return 0;

}
