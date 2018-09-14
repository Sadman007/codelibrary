#include <stdio.h>

int main()
{
    int a, b, c,d, i,j, result, res, t;
    scanf("%d", &t);
    while(t--){
       {
           scanf("%d %d %d", &a, &b, &c);
           for(j=1, a=a+b, result=0, d=10; d>=1; j++)
            {
                d=(a/c);
                res=(a%c);
                a=d+res;
                result=result+d;
            }
        printf("%d\n", result);
        }
    }


return 0;
}
