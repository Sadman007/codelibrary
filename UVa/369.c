#include <stdio.h>
int main()
{
    long long n , r;
    while(scanf("%lld %lld",&n,&r)==2 && n+r>0){
        long long ans=1 ;
        long long def = n - r , i;
        if(def>r) def=r;
        for(i=1;i<=def;i++){
            ans*=(n+1-i);
            ans/=i;
        }
        printf("%lld things taken %lld at a time is %lld exactly.\n", n ,r ,ans);

    }
    return 0;
}
