#include <stdio.h>
#include <math.h>

int main()
{
    double x,k;
    int p,q,i,j,xx;
    int cp,cq,t;
    scanf("%d",&t);
    while(t--)
    {
        xx=0;
        scanf("%lf%lf",&x,&k);
        cp=floor(x/k);
        cq=ceil(x/k);
        int upperlimit=x/cq;
        int downlimit=0;

        int pre_x=x;
        for(i=0; i<=upperlimit; i++)
        {
            for(j=0; j<=upperlimit; j++)
            {
                if((pre_x)-((i*cp)+(j*cq))==0)
                {
                    printf("%d %d\n",i,j);
                    xx++;
                }
            }
            if(xx>0) break;
        }
    }
    return 0;
}
