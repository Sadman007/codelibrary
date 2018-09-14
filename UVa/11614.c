#include <stdio.h>
#include <math.h>

int main() {
double n,t,d;
scanf("%lf",&t);
while(t--){
scanf("%lf",&n);
printf("%d\n",(int)((-1+sqrt(1+8*n))/2.0));
}
return 0;
}
