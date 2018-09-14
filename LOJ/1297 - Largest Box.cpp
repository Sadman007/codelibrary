#include <bits/stdc++.h>
using namespace std;

double solve(double W,double L)
{
    double a,b,c;
    a=12;
    b=(-4*(L+W));
    c=L*W;

    double x1,x2;
    x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
    x2 = (-b-sqrt(b*b-4*a*c))/(2*a);

    if(2*x1<L && 2*x1<W) return (L-2*x1)*(W-2*x1)*x1;
    return (L-2*x2)*(W-2*x2)*x2;
}

int main()
{
    int t;
    double W,L;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%lf%lf",&L,&W);
        printf("Case %d: %0.8lf\n",x,solve(W,L));
    }
    return 0;
}
