#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-7

int p,q,r,s,t,u;

double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double fd(double x)  // the derivative of function f
{
    return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;
}

double newton()
{
    if (f(0)==0) return 0;
    for (double x=0.5; ;)              // initial guess x = 0.5
    {
        double x1 = x - f(x)/fd(x);      // x1 = next guess
        if (fabs(x1-x) < EPS) return x;  // the guess is accurate enough
        x = x1;
    }
}

int main()
{
    while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        if (f(0) * f(1) > 0){
          puts("No solution");
        } else {
          printf("%.4lf\n", newton());
        }
    }
}
