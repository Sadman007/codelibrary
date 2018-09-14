#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,p,q;
    int egg[35];

    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        scanf("%d%d%d",&n,&p,&q);
        for(int i=0;i<n;i++) scanf("%d",&egg[i]);
        sort(egg,egg+n);
        int sum=0;
        int quantity=0;

        for(int i=0;i<min(p,n);i++)
        {
            if(sum+egg[i]>q) break;
            sum+=egg[i];
            quantity++;
        }
        printf("Case %d: %d\n",x,quantity);
    }
    return 0;
}

