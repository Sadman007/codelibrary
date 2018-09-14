#include <stdio.h>
#include <math.h>

int main()
{

    int i,p,x,count,a[4000],diff[4000];
    while(scanf("%d",&i)==1)
    {
        count=0;


        for(p=0; p<i; p++)
        {
            scanf("%d",&a[p]);
        }

        for(p=0; p<(i); p++)
        {
            diff[p]=0;
        }
        for(p=0; p<i-1; p++)
        {
            x=abs(a[p+1]-a[p]);
            diff[x]=1;
        }
        for(p=1; p<i; p++)
        {
            if(diff[p]==0)
                count=count+1;
        }

        if(count==0)
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");
        }

    }
    return 0;
}
