#include <stdio.h>
#include <math.h>

double pi = acos(-1);

int main()
{
    double  L, C, n;
    while(1)
    {
        scanf("%lf %lf %lf", &L, &C, &n);
        if(L<0&&C<0&&n<0) break;
        double LL = (1 + n*C)*L;
        double l = 0, r = pi/2, theta, R;
        int cnt = 0;
        while(l <= r && cnt < 50)
        {
            theta = (l+r)/2;
            R = L/2/sin(theta);
            if(R*2*theta < LL)
                l = theta;
            else
                r = theta;
            cnt++;
        }
        printf("%.3lf\n", R-R*cos(theta));
    }
    return 0;
}
