#include<stdio.h>
int main()
{
unsigned long long nm,n,x;
while(scanf("%llu",&nm)==1)
{
if(nm==0)break;
x=(nm*10)/9;
if(nm%9==0)printf("%llu %llu\n",x-1,x);
else printf("%llu\n",x);
}
return 0;
}
