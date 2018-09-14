#include <stdio.h>

int main()
{
long long int a,b,c,d,e,f,T,i,d1,d2,age;
scanf("%lld",&T);
for(i=1;i<=T;i++)
{
scanf("%lld/%lld/%lld",&a,&b,&c);
scanf("%lld/%lld/%lld",&d,&e,&f);
d1=a+b*30+c*365;
d2=d+e*30+f*365;
age=(d1-d2)/365;
if(d2>d1)
printf("Case #%lld: Invalid birth date\n",i);
else if(age>130)
printf("Case #%lld: Check birth date\n",i);
else
printf("Case #%lld: %d\n",i,age);
}
return 0;
}
