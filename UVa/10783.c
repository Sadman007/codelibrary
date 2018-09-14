#include <stdio.h>

int main() {

    int a,b,j=1,t;
    scanf ("%d",&t);
    while (j<=t){
    scanf ("%d%d",&a,&b);

    int sum=0;
    for (a;a<=b;a++){
        if (a%2!=0){
            sum=sum+a;
        }
    }
    printf ("Case %d: %d\n",j,sum);
    j++;
    }

    return 0;



}
