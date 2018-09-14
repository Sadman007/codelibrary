#include<stdio.h>
#include<math.h>
int main()
{
     int n,i;
     double u,v,d;
      double t1,t2,t,a;
      scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&d,&v,&u);
            if((v>=u)||(v<=0)||(u<=0)||(d<=0))
            printf("Case %d: can't determine\n",i);
            else
            {
            a=sqrt(u*u-v*v);
            t1=d/a;
            t2=d/u;
            t=t1-t2;
            printf("Case %d: %.3lf\n",i,t);
            }
        }
    return 0;
}
