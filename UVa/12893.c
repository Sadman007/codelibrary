#include <stdio.h>

int main(){
    long long int t,n,i,count;
    scanf("%lld",&t);
    while(t--){
        count=0;
        scanf("%lld",&n);
        for(i=n;i>0;){
            if(i%2==1) count++;
            i=i/2;
        }
    printf("%lld\n",count);
    }
return 0;
}
