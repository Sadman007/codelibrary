#include <stdio.h>

long long int prime(long long int a){
    long long int i;
    if(a==0||a==1) return 1;
    for(i=2;i*i<=a;i++){
        if(a%i==0) return 1;
    }
return 0;
}

int main(){

long long int a,i,count1,count2,j,sum;
while(scanf("%lld",&a)==1){
if(a==0) break;
count1=0,count2=0;
for(i=a;i>0;i--){
    count1++;
    if(prime(i)==0) break;
}
j=a+250;
for(i=a;i<=j;i++){
    count2++;
    if(prime(i)==0) break;
}
sum=count1+count2-2;
printf("%lld\n",sum);
}
return 0;
}
