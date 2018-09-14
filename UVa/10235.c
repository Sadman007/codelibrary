#include <stdio.h>

long long int prime(long long int a){
    long long int n;
    for(n=2;n*n<=a;n++){

    if (a % n == 0)
    return 0;
    }
    return 1;

}

long long int rev(long long int z){
    long long int reverse=0;
    while(z!=0){
        reverse = reverse * 10;
        reverse = reverse + z%10;
        z       = z/10;
    }
return reverse;
}


int main() {

long long int a;
while(scanf("%lld",&a)==1){


if(prime(a)!=1) {printf("%lld is not prime.\n",a);}
else {
    int r=rev(a);
if(prime(r)==1&&a!=r) printf("%lld is emirp.\n",a);
else printf("%lld is prime.\n",a);
}
}
 return 0;
}
