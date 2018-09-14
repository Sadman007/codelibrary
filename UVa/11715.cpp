#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,cas=1;
    double a,b,c;
    while(scanf("%d",&n)==1)
    {   if(n==0) break;
        scanf("%lf%lf%lf",&a,&b,&c);
        if(n==1)
        {
            double acc=(b-a*1.0)/c;
            double s=(b*b-a*a)/(2*acc);
            printf("Case %d: %0.3lf %0.3lf\n",cas++,s,acc);
        }
        if(n==2)
        {
            double s=(b*b-a*a)/(2*c);
            double t=(b-a)/c;
            printf("Case %d: %0.3lf %0.3lf\n",cas++,s,t);
        }
        if(n==3)
        {
            double v=sqrt(a*a+(2*b*c));
            double t=(v-a)/b;
            printf("Case %d: %0.3lf %0.3lf\n",cas++,v,t);
        }
        if(n==4)
        {
            double v=sqrt(a*a-(2*b*c));
            double t=(a-v)/b;
            printf("Case %d: %0.3lf %0.3lf\n",cas++,v,t);
        }

    }
    return 0;
}
