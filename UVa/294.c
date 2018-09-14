#include <stdio.h>
#include <math.h>

long long int prime(long long int a){
    long long int i;
    for(i=2;i*i<=a;i++){
        if(a%i==0)
            return 0;
    }
    return 1;

}

long long int fact(long long int a){
    long long int i,num=0,j;
    j=sqrt(a);
    if(a==1) return 1;
    else if(prime(a)==1) return 2;
    else {
    for(i=1;i<=j;i++){
        if(a%i==0) {
        num++;
        if(i*i!=a) num++;
    }
    }
    return num;
    }
}
int main(){

long long int a,b,i,max,num,div,t,t1;
scanf("%lld",&t);

while(t--){
    scanf("%lld%lld",&a,&b);
if(a>b){
    t1=a;
    a=b;
    b=t1;
}

if(a==b) printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,a,fact(a));
else {
max=0;
for(i=a;i<=b;i++){
    div=fact(i);
    if(max<div){
        max=div;
        num=i;
    }
}

printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,num,max);
}
}
return 0;
}
