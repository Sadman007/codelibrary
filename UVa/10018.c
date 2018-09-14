#include <stdio.h>

long long int rev(long long int a){
    long long int rem,reverse=0;
while(a!=0)
  {
     rem=a%10;
     reverse=reverse*10+rem;
     a/=10;
  }
return reverse;
}

int main(){
long long int n,count,sum,t,p;
scanf("%lld",&t);
while(t--){
count=0,sum=0;
scanf("%lld",&n);
sum=n;
while(n!=rev(n)){
    sum=sum+rev(n);
    n=sum;
    count++;
}
printf("%lld %lld\n",count,sum);
}
return 0;
}
