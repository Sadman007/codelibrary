#include <stdio.h>

long long int a[10000000];

long long int prime(long long int a)
{
    long long int i;
    if(a==0||a==1) return 1;
    for(i=2; i*i<=a; i++)
    {
        if(a%i==0) return 1;
    }
    return 0;
}

int main(){
    long long int i,j=0,n,k;
    for(i=0;i<=1000000;i++){
        if(prime(i)==0) a[j++]=i;
    }
    scanf("%lld",&n);
        if(n%a[j]==0) {
printf("%lld\n",a[j]);
return 0;
        }
        else j--;
}
