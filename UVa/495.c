#include <stdio.h>
#include <math.h>

int main() {

    int n;
    while (scanf ("%d",&n)==1) {

    double shi,fib;
    shi=(1+sqrt(5))/2.0;
    fib = (pow(shi,n)-pow((1-shi),n))/(sqrt(5));

    printf ("The Fibonacci number for %d is %0.lf\n",n,fib);

    }
    return 0;

}
