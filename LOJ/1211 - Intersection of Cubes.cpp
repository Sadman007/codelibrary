#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;

    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d",&n);
        int x1,x2,y1,y2,z1,z2,xst,yst,zst,xen,yen,zen;
        x1=y1=z1=0;
        x2=y2=z2=10000;

        while(n--)
        {
            scanf("%d%d%d%d%d%d",&xst,&yst,&zst,&xen,&yen,&zen);
            x1=max(x1,xst);
            y1=max(y1,yst);
            z1=max(z1,zst);
            x2=min(x2,xen);
            y2=min(y2,yen);
            z2=min(z2,zen);
        }

        printf("Case %d: %d\n",x,max(0,(x2-x1)*(y2-y1)*(z2-z1)));
    }
    return 0;
}

