#include <stdio.h>
#include <string.h>

int main()
{   char a[10000] = {0},b[10000] = {0} ;
    int i,j,k,value,r, temp;
    int c[10000] = {0};
    int car1,car2;

    while(scanf("%s %s",a,b)==2)
    {
        int n1 = strlen(a);
        int n2 = strlen(b);
        car1=atoi(a);
        car2=atoi(b);
        if(car1==0||car2==0) { printf("0\n"); continue; }
        for(i = n1 - 1; i >= 0; i--)
        {
            r = 0;
            for(j = n2 - 1,k = n1 - i - 1; j >= 0; j--,k++)
            {
                value = (a[i] - '0') * (b[j] - '0');
                temp = c[k];
                c[k] = (c[k] + value + r) % 10;
                r = (value + r + temp) / 10;
            }
            if(r != 0) c[k] = r;
        }
        int x = k;
        if(c[k] == 0) x--;
        for(i = x; i >= 0; i--)
        {
            printf("%d",c[i]);
        }
       for(i=0;i<10000;i++){
            a[i]=0;
            b[i]=0;
            c[i]=0;
        }
        i=0;
        j=0;
        k=0;
        r=0;
        temp=0;
        value=0;

        printf("\n");
    }
    return 0;
}
