#include <stdio.h>
#include <math.h>

int main() {
    double x,y,x1,x2,x3,y1,y2,y3,mr,mt;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6){

    mr=(y2-y1)/(x2-x1);
    mt=(y3-y2)/(x3-x2);

    x=((mr*mt*(y3-y1))+(mr*(x2+x3))-(mt*(x1+x2)))/(2*(mr-mt));
    y=((-1/mr)*(x-((x1+x2)/2.0)))+((y1+y2)/2.0);

    double r;
    r=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));

    double cir;
    cir=2*acos(-1)*r;

    printf ("%0.2lf\n",cir);

    }
return 0;

}
