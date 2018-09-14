#include <stdio.h>
long long int mod(long long int X, long long int n, long long int M)
{
    if(n==0) return 1;

    if(n%2) return ((X%M)*mod(X,n-1,M))%M;

    else
    {
        long long int d = mod(X,n/2,M);
        return ((d%M)*(d%M))%M;
    }
}

int main() {
long long int a,b,c;
while(scanf("%lld%lld%lld",&a,&b,&c)==3){
    printf("%lld\n",mod(a,b,c));
}
return 0;
}
