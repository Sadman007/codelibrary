#include<stdio.h>
#include<math.h>
int main() {
double r,n,a, pi=acos(-1.0);
 while(scanf("%lf%lf",&r,&n)==2){
 a=r*r*n/2*sin(2.0*pi/n);
  printf("%.3lf\n",a);
   }
   return 0;
    }
