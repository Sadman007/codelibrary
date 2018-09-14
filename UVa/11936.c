#include <stdio.h>

int main() {

   long long int a,b,c,t,t1,t2;
    scanf("%lld",&t);
    while(t--){

        scanf("%lld%lld%lld",&a,&b,&c);


        if(a+b>c&&b+c>a&&c+a>b){
            printf("Ok\n");
        }
        else {printf("Wrong!!\n");
        }
    }
return 0;
}
