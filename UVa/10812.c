#include<stdio.h>

int main()
{
int a,b,x,y,i=1,t;
scanf("%d",&t);
while (i<=t)
           {
        scanf("%d %d",&a,&b);
                  if (a>=b&&(a+b)%2==0)
                   {
                   x=(a+b)/2;
                   y=(a-b)/2;
                   printf("%d %d\n",x,y);
                   }
         else
         printf("impossible\n");
         i++;
          }
return 0;
}
