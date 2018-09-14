#include <bits/stdc++.h>
using namespace std;
int ara[500050];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        int st,en,q,ans,qr;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&qr);
            ans=-1;
            for(int j=0;j<n;j++)
            {
                if(qr>ara[j]) ans=ara[j];
                else break;
            }
            if(ans==-1) printf("X ");
            else printf("%d ",ans);
            ans=-1;
            for(int j=n-1;j>=0;j--)
            {
                if(qr<ara[j]) ans=ara[j];
                else break;
            }
            if(ans==-1) printf("X\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
