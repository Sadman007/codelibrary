#include <bits/stdc++.h>
using namespace std;

int diff(int a,int b)
{
    if((a-b)>0) return (a-b);
    return (-1)*(a-b);

}

int main()
{
    int a[100000],n,i,j,t1,t2,m;
    while(scanf("%d",&n)==1)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        t1=0;
        t2=m;
        for(i=0; i<n-1; i++)
        {
            for(j=0; j<n; j++)
            {
                if(a[i]+a[j]==m&&(diff(a[i],a[j])<diff(t1,t2)))
                {
                    t1=a[i];
                    t2=a[j];
                }
            }
        }
        if(t1>t2) swap(t1,t2);
        printf("Peter should buy books whose prices are %d and %d.\n\n",t1,t2);
    }
    return 0;
}
