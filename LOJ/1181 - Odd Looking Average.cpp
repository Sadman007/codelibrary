#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cs=0,t,k;
    scanf("%d",&t);
    while(t--)
    {
        double a,b;
        scanf("%d%lf%lf",&k,&a,&b);
        double res = pow(b,(double)(k+1))-pow(a,(double)(k+1));

        if(abs(res)<=1e-7)
        {
            res=pow(b,k);
        }
        else
        {
            res/=(k+1)*(b-a);
        }
        printf("Case %d: %0.8lf\n",++cs,res);
    }
    return 0;
}
