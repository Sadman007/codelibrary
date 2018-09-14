#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)

double dist(double x1,double y1,double x2,double y2)
{
    double d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return sqrt(d);
}

int main()
{
    int t;
    double c1x,c1y,r1,c2x,c2y,r2,ans,ans1,ans2,angle1,angle2,d;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&c1x,&c1y,&r1,&c2x,&c2y,&r2);
        d = dist(c1x,c1y,c2x,c2y);

        if(d>=(r1+r2)) ans=0.0;
        else if(d+r1<=r2) ans = pi * r1 * r1;
        else if(d+r2<=r1) ans = pi * r2 * r2;
        else
        {
            angle1 = acos((d*d+r1*r1-r2*r2)/(2*d*r1));
            angle2 = acos((d*d+r2*r2-r1*r1)/(2*d*r2));

            ans1 = angle1*r1*r1 - 0.5*r1*r1*sin(2*angle1);
            ans2 = angle2*r2*r2 - 0.5*r2*r2*sin(2*angle2);

            ans = ans1+ans2;
        }
        printf("Case %d: %0.8lf\n",x,ans);
    }
    return 0;
}
