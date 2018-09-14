#include <stdio.h>

int main()
{

  double a,b,factorial=1;
  while (scanf("%lf",&a)==1) {

  for ( b=1 ; b<=a ; b++)
    factorial = factorial*b;

    if (factorial>6227020800) {
        printf ("Overflow!\n");
    }
    else if (factorial<10000) {
        printf ("Underflow!\n");
    }

  else {
        printf ("%0.lf\n", factorial);

  }}
  return 0;
}
