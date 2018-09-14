#include <stdio.h>

int main(){

long long int n;
char c='%';
while(scanf("%lld",&n)==1){
    if(n<0) break;
    else if(n==1) printf("0%c\n",c);
    else printf("%lld%c\n",n*25,c);
}
return 0;
}
