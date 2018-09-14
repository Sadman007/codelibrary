#include <stdio.h>
#include<math.h>
main()
{
    double x1, x2, x3, y1, y2, y3;
    double p, q, r, s, t, u, v, w, R;
    double h, k;
    double c, d, e;
    double h1, k1, c1, d1, e1;
    char ch1 = '+';
    char ch2 = '-';

     while((scanf("%lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3) == 6)){
     p = x2 - x1;
     q = x2 + x1;
     r = y2 - y1;
     s = y2 + y1;
     t = x3 - x2;
     u = x3 + x2;
     v = y3 - y2;
     w = y3 + y2;
     h = ((p * q * v) + (r * s * v) - (u * r * t) - (v * w * r)) / (((p * v) - (r * t)) * 2);
     k =  ((p * q * t) + (r * s * t) - (u * p * t) - (v * w * p)) / (2 * (r * t - p * v));
     R = ((x1 - h) * (x1 - h)) + ((y1 - k) * (y1 - k));
     r = sqrt(R);
     c = - 2 * h;
     d = - 2 * k;
     e = (h * h) + (k * k) - R;
     h1 = fabs(h);
     k1 = fabs(k);
     c1 = fabs(c);
     d1 = fabs(d);
     e1 = fabs(e);
     printf("(x %c %0.3lf)^2 + (y %c %0.3lf)^2 = %0.3lf^2\n", (h >= 0)? ch2 : ch1, h1, (k >= 0)? ch2 : ch1, k1, r);
     printf("x^2 + y^2 %c %0.3lfx %c %0.3lfy %c %0.3lf = 0\n", (c < 0)? ch2 : ch1, c1, (d < 0)? ch2 : ch1, d1, (e > 0)? ch1 : ch2, e1);
     printf("\n");

    }
    return 0;


     }
