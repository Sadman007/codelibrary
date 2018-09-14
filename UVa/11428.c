#include <stdio.h>

int main() {
    long long int a,i,j,sum,flag;
    while(scanf("%lld",&a)==1){
        if(a==0) break;
        flag = 0;
        for(i=1;i<=a && flag==0 ;i++){
            for(j=0;j<=i;j++){
                sum=(i*i*i)-(j*j*j);
                if(sum==a){
                    flag = 1;
                    printf("%lld %lld\n",i,j);
                    break;
                }
            }
        }
        if (flag == 0) printf("No solution\n");
    }
    return 0;
}
