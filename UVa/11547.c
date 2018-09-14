#include <stdio.h>
#include <math.h>

int main()
{   int T,i=1;
    scanf ("%d",&T);
    for (i=1;i<=T;i++){
    int a;
    scanf ("%d",&a);

    int s;
    s = ((((((a*567)/9)+7492)*235)/47)-498);

    int p,ten;
    p = s/10;
    ten = p%10;
    int tenp = abs(ten);

     printf ("%d\n",tenp);
    }

    return 0;
}
