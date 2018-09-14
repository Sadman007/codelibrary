#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cs=1, t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d,r;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a!=29 || b!=2) r = d-c;
        else
        {
            int a1 = d/4-d/100+d/400;
            int a2 = c/4-c/100+c/400;
            r = a1-a2;
        }
        printf("Case %d: %d\n",cs++,r);
    }
    return 0;
}
