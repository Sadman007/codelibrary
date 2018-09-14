#include <stdio.h>

int main() {

long long int a,ans;
while(scanf("%lld",&a)==1){
if(a==0) break;
printf("%lld\n",a*(a+1)*(2*a+1)/6);
}
return 0;
}
