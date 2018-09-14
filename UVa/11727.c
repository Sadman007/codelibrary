#include <stdio.h>

int main()
{
int T,i=1,a[3];
scanf("%d",&T);
        while(i<=T)
            {
             scanf("%d%d%d",&a[0],&a[1],&a[2]);
             sort(a,a+3);
             printf("Case %d: %d\n",i++,a[1]);
             }
return 0;
}
