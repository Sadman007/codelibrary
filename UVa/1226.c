#include <stdio.h>

int main()
{
    int a[10],i,test;
    int n,dec,mod,t;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0; i<10; i++) a[i]=0;
        for(i=1; i<=n; i++)
        {
            t=i;
            while(t>0)
            {
                mod=t%10;
                a[mod]++;
                t=t/10;
            }
        }
        for(i=0; i<9; i++) printf("%d ",a[i]);
        printf("%d\n",a[9]);
    }
    return 0;
}
