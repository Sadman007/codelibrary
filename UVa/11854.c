#include <stdio.h>


int main() {

long long int a,b,c;
while(scanf("%lld%lld%lld",&a,&b,&c)==3){
    if (a,b,c==0) break;
   long long int a1,b1,c1;
   a1=a*a;
   b1=b*b;
   c1=c*c;
if (a1==b1+c1 || b1==a1+c1 || c1==a1+b1) {
    printf("right\n");
}
else printf("wrong\n");
}
return 0;
}
