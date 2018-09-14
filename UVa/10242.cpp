#include <bits/stdc++.h>

using namespace std;
double area(double ax,double ay,double bx,double by,double cx,double cy)
{
    return (ax-bx)*(by-cy) - (ay-by)*(bx-cx);
}
double corrector(double a)
{
    if(a-0.00000000000000000==0.0) return 0;
    return a;
}
int main()
{   double tax,tay,tbx,tby,tcx,tcy,tdx,tdy;
    double ax,ay,bx,by,cx,cy,dx,dy,x,y;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&tax,&tay,&tbx,&tby,&tcx,&tcy,&tdx,&tdy)==8)
    {
        if(tax==tbx&&tay==tby)
    {
        bx=tax;
        by=tay;
        cx=tbx;
        cy=tby;
        ax=tcx;
        ay=tcy;
        dx=tdx;
        dy=tdy;
    }
    else if(tax==tcx&&tay==tcy)
    {
        bx=tax;
        by=tay;
        cx=tcx;
        cy=tcy;
        ax=tbx;
        ay=tby;
        dx=tdx;
        dy=tdy;
    }
    else if(tax==tdx&&tay==tdy)
    {
        bx=tax;
        by=tay;
        cx=tdx;
        cy=tdy;
        ax=tbx;
        ay=tby;
        dx=tcx;
        dy=tcy;
    }

    else if(tbx==tdx&&tby==tdy)
    {
        bx=tbx;
        by=tby;
        cx=tdx;
        cy=tdy;
        ax=tax;
        ay=tay;
        dx=tcx;
        dy=tcy;
    }
    else if(tcx==tdx&&tcy==tdy)
    {
        bx=tcx;
        by=tcy;
        cx=tdx;
        cy=tdy;
        ax=tax;
        ay=tay;
        dx=tbx;
        dy=tby;
    }
    else
    {
        ax=tax;
        ay=tay;
        cx=tcx;
        cy=tcy;
        bx=tbx;
        by=tby;
        dx=tdx;
        dy=tdy;

    }

        double ar=area(ax,ay,bx,by,dx,dy);
        double A1,B1,C1,A2,B2,C2,X1,Y1,D;
        A1=ay-dy;
        B1=dx-ax;
        C1=ar+ay*dx-ax*dy;
        X1=((ax+dx)/2.0);
        Y1=((ay+dy)/2.0);
        A2=Y1-by;
        B2=bx-X1;
        C2=bx*Y1-by*X1;
        D=(A1*B2-A2*B1);
        x=(C1*B2-C2*B1)/D;
        y=(A2*C1-A1*C2)/(-1*D);
        if(ax==0&&ay==0&&bx==0&&by==0&&cx==0&&cy==0&&dx==0&&dy==0) {x=0; y=0;}
        printf("%0.3lf %0.3lf\n",corrector(x),corrector(y));

    }
    return 0;
}
