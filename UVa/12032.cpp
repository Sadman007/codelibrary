#include <bits/stdc++.h>
using namespace std;
int a[100010],k,d;

int main()
{
    int n,i,t,mx,cas=1,answer;
    scanf("%d",&t);
    while(t--)
    {
        mx=0;
        answer=0;
        scanf("%d",&n);
        a[0]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            d=a[i]-a[i-1];
            if(d>mx) mx=d;
        }
        answer=mx;
        for(i=1; i<=n; i++)
        {
            d=a[i]-a[i-1];
            if(d==mx) mx--;
            else if(d>mx)
            {
                answer++;
                break;
            }
        }
        printf("Case %d: %d\n",cas++,answer);
    }
    return 0;
}
