#include <stdio.h>

int main()
{

    int n,i,j,ara[1000];
    while(scanf("%d",&n)==1)
    {
        j=0;
        if(n<0) break;
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        while(n>0)
        {
            ara[j++]=n%3;
            n=n/3;
        }
        for(i=j-1; i>=0; i--)printf("%d",ara[i]);
        printf("\n");
    }
    return 0;
}
