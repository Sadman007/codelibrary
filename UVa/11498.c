#include<stdio.h>


int main()
{
    long n,x,x1,y1,y,t1,i;
    while(scanf("%ld",&n)==1)
    {
    if(n==0)
    break;
    scanf("%ld%ld",&x,&y);
    for(i=0;i<n;i++)
      {
      scanf("%ld%ld",&x1,&y1);
      if(x==x1||y==y1)
      printf("divisa\n");
      if(x1>x&&y1>y)
      printf("NE\n");
      if(x1<x&&y1>y)
      printf("NO\n");
        if(x1<x&&y1<y)
      printf("SO\n");
        if(x1>x&&y1<y)
      printf("SE\n");
      }
    }
}
