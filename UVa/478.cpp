#include <bits/stdc++.h>
using namespace std;
double area(double a,double b,double c,double d,double e,double f)
{
    return 0.5*((a-c)*(d-f)-(b-d)*(c-e));
}

int circle_check(double x,double y,double r,double a,double b)
{
    double length=(x-a)*(x-a)+(y-b)*(y-b);
    if(length<(r*r)) return 0;
    return 1;
}
int tri_check(double x1,double y1,double x2,double y2,double x3,double y3,double a,double b){
    double area1,area2,area3,area_t;
    area1=area(x1,y1,x2,y2,a,b);
    area2=area(a,b,x2,y2,x3,y3);
    area3=area(a,b,x3,y3,x1,y1);
    if((area1>0 && area2>0 && area3>0)||((area1<0 && area2<0 && area3<0))) return 0;
    return 1;
}
int rec_check(double tx,double ty,double dx,double dy,double a,double b)
{
    double t1x,t1y,d1x,d1y;
    t1x=dx;
    t1y=ty;
    d1x=tx;
    d1y=dy;
    double a1,a2,a3,a4,a_t;
    a1=area(tx,ty,d1x,d1y,a,b);
    a2=area(a,b,d1x,d1y,dx,dy);
    a3=area(a,b,dx,dy,t1x,t1y);
    a4=area(a,b,t1x,t1y,tx,ty);
    a_t=2*area(tx,ty,d1x,d1y,dx,dy);
    if(fabs(a_t-(a1+a2+a3+a4)) <= 1e-9 && (a1>0&&a2>0&&a3>0&&a4>0)) return 0;
    return 1;
}
struct data
{
    char s;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    int holding_number;
} info[100];
int main()
{
    char s;
    double px,py;
    double x,y,r,a,b,c,d,e,f;
    int i=1;
    while(1)
    {
        cin >> info[i].s;
        if(info[i].s=='*') break;
        if(info[i].s=='c')
        {
            scanf("%lf%lf%lf",&x,&y,&r);
            info[i].a=x;
            info[i].b=y;
            info[i].c=r;
            info[i].holding_number=i;
        }
        if(info[i].s=='r')
        {
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            info[i].a=a;
            info[i].b=b;
            info[i].c=c;
            info[i].d=d;
            info[i].holding_number=i;
        }
        if(info[i].s=='t')
        {
            scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
            info[i].a=a;
            info[i].b=b;
            info[i].c=c;
            info[i].d=d;
            info[i].e=e;
            info[i].f=f;
            info[i].holding_number=i;
        }
        i++;
    }
    int j,cnt=0,flag=0;
    while(1)
    {
        cnt++;
        cin >> px >> py;
        if(px==9999.9&&py==9999.9) break;
        for(j=1; j<i; j++)
        {
            if(info[j].s=='r')
            {
                if(rec_check(info[j].a,info[j].b,info[j].c,info[j].d,px,py)==0)
                {
                    printf("Point %d is contained in figure %d\n",cnt,info[j].holding_number);
                    flag=1;
                }
            }
            if(info[j].s=='c')
            {
                if(circle_check(info[j].a,info[j].b,info[j].c,px,py)==0)
                {
                    printf("Point %d is contained in figure %d\n",cnt,info[j].holding_number);
                    flag=1;
                }
            }
            if(info[j].s=='t')
            {
                if(tri_check(info[j].a,info[j].b,info[j].c,info[j].d,info[j].e,info[j].f,px,py)==0)
                {
                    printf("Point %d is contained in figure %d\n",cnt,info[j].holding_number);
                    flag=1;
                }
            }
        }
        if(flag==0) printf("Point %d is not contained in any figure\n",cnt);
        flag=0;
    }
    return 0;
}
