#include <stdio.h>

int main() {

    int i,N,set=1;
    while ((scanf ("%d",&N)==1)) {
            if (N==0) break;

    int ara[N];
    for (i=0;i<N;i++){
        scanf ("%d",&ara[i]);
        }
    int sum=0;
    for (i=0;i<N;i++) {
        sum=sum+ara[i];
        }
    int avg;
    avg=sum/N;
    int ans=0;
    for (i=0;i<N;i++) {
        if (ara[i]>avg){
        ans=ans+(ara[i]-avg);
        }
        }

        printf ("Set #%d\nThe minimum number of moves is %d.\n\n",set,ans);
        set++;

    }

        return 0;
}
