#include <stdio.h>

int main()
{
    int T,i=1;
    scanf ("%d",&T);
    while (i<=T) {
    int N,j=0;

    scanf ("%d",&N);

    int ara[N];
    for (j=0;j<N;j++) {
    scanf ("%d",&ara[j]);
    }

    printf ("Case %d: %d\n",i,ara[j/2]);
    i++;
    }
    return 0;
}
